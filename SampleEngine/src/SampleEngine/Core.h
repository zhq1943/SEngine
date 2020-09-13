#pragma once

#ifdef SE_PLATEFORM_WINDOWS
    #ifdef SE_BUILD_DLL
        #define SE_API __declspec(dllexport)
    #else
        #define SE_API __declspec(dllimport)
    #endif
#else
#error Only from windows
#endif
       