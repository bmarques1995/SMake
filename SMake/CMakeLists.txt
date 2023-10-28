cmake_minimum_required(VERSION 3.22)

file(GLOB_RECURSE SM_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "./include/*.hh")
file(GLOB_RECURSE SM_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ".//*.cc")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_PREFIX_PATH})

#find_package(JsonCpp REQUIRED)

set(LIB_POSTFIX d)

if(BUILD_SHARED_LIBS)
    set(LIB_NAME ${CMAKE_PROJECT_NAME}_dynamic)
    add_library(${LIB_NAME} SHARED ${SM_HDRS} ${SM_SRCS})
    target_precompile_headers(${LIB_NAME} PRIVATE ./include/private/smpch.hh)
    target_include_directories(${LIB_NAME} PUBLIC "${CMAKE_PREFIX_PATH}/include" "${CMAKE_CURRENT_SOURCE_DIR}/include/public")
    target_include_directories(${LIB_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/private")
    target_link_directories(${LIB_NAME} PUBLIC "${CMAKE_PREFIX_PATH}/lib")
    target_link_libraries(${LIB_NAME} PUBLIC)
    target_compile_definitions(${LIB_NAME} PUBLIC SMAKE_DYNAMIC_LINK)
    target_compile_definitions(${LIB_NAME} PRIVATE SMAKE_BUILD_DLL)
    if(WIN32)
        target_compile_definitions(${LIB_NAME} PUBLIC SMAKE_WINDOWS)
        set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    endif()

    set_target_properties(${LIB_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/bin")
    set_target_properties(${LIB_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_PREFIX_PATH}/bin")
    set_target_properties(${LIB_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_PREFIX_PATH}/bin")
    set_target_properties(${LIB_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/lib")
    set_target_properties(${LIB_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_PREFIX_PATH}/lib")
    set_target_properties(${LIB_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_PREFIX_PATH}/lib")
    set_target_properties(${LIB_NAME} PROPERTIES CXX_STANDARD 17)
    set_target_properties(${LIB_NAME} PROPERTIES DEBUG_POSTFIX ${LIB_POSTFIX})
endif()

if(BUILD_STATIC_LIBS OR BUILD_EXECUTABLE)
    set(LIB_NAME ${CMAKE_PROJECT_NAME}_static)
    add_library(${LIB_NAME} STATIC ${SM_HDRS} ${SM_SRCS})
    target_precompile_headers(${LIB_NAME} PRIVATE ./include/private/smpch.hh)
    target_include_directories(${LIB_NAME} PUBLIC "${CMAKE_PREFIX_PATH}/include" "${CMAKE_CURRENT_SOURCE_DIR}/include/public")
    target_include_directories(${LIB_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/private")
    target_link_directories(${LIB_NAME} PUBLIC "${CMAKE_PREFIX_PATH}/lib")
    target_link_libraries(${LIB_NAME} PUBLIC)

    if(WIN32)
        target_compile_definitions(${LIB_NAME} PUBLIC SMAKE_WINDOWS)
    endif()

    set_target_properties(${LIB_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/bin")
    set_target_properties(${LIB_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_PREFIX_PATH}/bin")
    set_target_properties(${LIB_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_PREFIX_PATH}/bin")
    set_target_properties(${LIB_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/lib")
    set_target_properties(${LIB_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_PREFIX_PATH}/lib")
    set_target_properties(${LIB_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_PREFIX_PATH}/lib")
    set_target_properties(${LIB_NAME} PROPERTIES CXX_STANDARD 17)
    set_target_properties(${LIB_NAME} PROPERTIES DEBUG_POSTFIX ${LIB_POSTFIX})
endif()

install(TARGETS ${CMAKE_PROJECT_NAME}_dynamic
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}"
        ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}")
install(TARGETS ${CMAKE_PROJECT_NAME}_static
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}"
        ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}")