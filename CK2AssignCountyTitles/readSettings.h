#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <stdexcept>
using std::ifstream;
using std::string;
using std::istringstream;
using std::stoi;
using std::getline;

struct settingVals {
    string provincesPath;
    string titlesPath;
    string provincesRequiringTitles;
    string titleHolderDate;
    int holderIDToProvinceIDMultiplier;
    int holderIDToProvinceIDAdditiveConstant;
    int numBracketsToSkip;
};

settingVals readSettings();
string readProperty(ifstream& ifs, const string& propertyName);