#pragma once
#include <iostream>
#include <stdexcept>
#include <dirent.h>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::string;
using std::stringstream;
using std::unordered_map;
using std::ofstream;

unordered_map<string, int> createProvinceNameToIDMap(string provincesPath);