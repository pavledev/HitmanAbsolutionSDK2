#pragma once

#include <Windows.h>
#include <fstream>
#include <iostream>

#define HM5_LOG(format, ...) fprintf(stdout, format, __VA_ARGS__)

//using namespace std;

class HM5DebugConsole
{
private:
	static FILE* file;
public:
	static void Initialize();
	static void Close();
};
