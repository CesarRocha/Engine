//================================================================
//              Utilities.hpp                                  
//================================================================
#pragma once
#ifndef _Utilities_
#define _Utilities_
#include <Windows.h>
#include <string>
#include <fstream>
#include <iostream>
#include "stdarg.h"

std::string ConsolePrintf(const char* messageFormat, ...);
bool DoesFileExist(const std::string fileName);
char* ReadFile(std::string filePath);


#endif //!_Utilities_