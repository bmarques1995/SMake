#ifndef SMAKE_HH
#define SMAKE_HH

#ifdef SMAKE_WINDOWS
	#ifdef SMAKE_DYNAMIC_LINK
		#ifdef SMAKE_BUILD_DLL
			#define SMAKE_API __declspec(dllexport)
		#else
			#define SMAKE_API __declspec(dllimport)
		#endif
	#else
		#define SMAKE_API
	#endif
#else
	#define SMAKE_API
#endif

#endif