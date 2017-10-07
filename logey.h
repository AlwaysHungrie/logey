#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <chrono>

void captureKey(int key, std::string filename);
void createFileHeader(std::string filename);
void createTimeStamp(std::string filename);
bool fileExists(std::string filename);