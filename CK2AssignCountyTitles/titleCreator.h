#pragma once
#include <iostream>
#include <stdexcept>
#include <dirent.h>
#include <fstream>
#include <sstream>
#include <io.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "readSettings.h"
using std::string;
using std::to_string;
using std::getline;
using std::stringstream;
using std::unordered_map;
using std::unordered_set;
using std::ofstream;
using std::ifstream;


void CreateTitles(const settingVals& setVal, const unordered_map<string, int>& provinceNameToIDMap, const unordered_set<int>& provinceReqTitles);
void CreateTitle(const settingVals& setVal, const dirent* ent, int provID);