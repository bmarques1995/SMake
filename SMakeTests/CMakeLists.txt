cmake_minimum_required(VERSION 3.22)

set(TARGET_NAME SMakeTests)

file(GLOB_RECURSE SM_TESTS_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "./*.cc")

find_package(GTest REQUIRED)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_PREFIX_PATH})

enable_testing()
add_executable(${TARGET_NAME} ${SM_TESTS_SRCS})
target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src" "${CMAKE_PREFIX_PATH}/include" "${PROJECT_SOURCE_DIR}/SMake/include/SMake")
target_link_directories(${TARGET_NAME} PUBLIC "${CMAKE_PREFIX_PATH}/lib")
target_link_libraries(${TARGET_NAME} PRIVATE SMake_dynamic GTest::gtest_main GTest::gtest GTest::gmock_main GTest::gmock)
add_test(
    NAME ${TARGET_NAME}
    COMMAND ${TARGET_NAME}
)

set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/lib")
set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_PREFIX_PATH}/lib")
set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_PREFIX_PATH}/lib")
set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17)

install(TARGETS ${TARGET_NAME}
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}"
        ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}")