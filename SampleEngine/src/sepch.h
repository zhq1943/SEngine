#pragma once

#include<iostream>
#include<memory>
#include<utility>
#include<algorithm>
#include<functional>

#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

#include"SampleEngine/CLog.h"

#ifdef SE_PLATEFORM_WINDOWS
#include<Windows.h>
#endif

#if defined(_MSC_VER) && !defined(_CRT_SECURE_NO_WARNINGS)
#define _CRT_SECURE_NO_WARNINGS
#endif