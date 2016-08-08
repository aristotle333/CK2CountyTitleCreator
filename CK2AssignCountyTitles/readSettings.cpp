#include "readSettings.h"

settingVals readSettings() {
    settingVals setVals;
    ifstream ifs("settings.txt");
    string line;

    setVals.provincesPath = readProperty(ifs, "provincesPath");
    setVals.titlesPath = readProperty(ifs, "titlesPath");
    setVals.provincesRequiringTitles = readProperty(ifs, "provincesRequiringTitles");
    setVals.titleHolderDate = readProperty(ifs, "titleHolderDate");
    setVals.holderIDToProvinceIDMultiplier = stoi(readProperty(ifs, "holderIDToProvinceIDMultiplier"));
    setVals.holderIDToProvinceIDAdditiveConstant = stoi(readProperty(ifs, "holderIDToProvinceIDAdditiveConstant"));
    setVals.numBracketsToSkip = stoi(readProperty(ifs, "numBracketsToSkip"));
    ifs.close();

    return setVals;
}

string readProperty(ifstream& ifs, const string& propertyName) {
    string line;
    if (getline(ifs, line)) {
        istringstream ss(line);
        string property;
        ss >> property;
        if (property == propertyName) {
            int startIdx = line.find('"') + 1;
            int endIdx = line.find('"', startIdx);
            return line.substr(startIdx, endIdx - startIdx);
        }
        else {
            std::cerr << "Error ready the property " << propertyName << " from the settings.txt file";
            throw std::exception();
        }
    }
    else {
        std::cerr << "Error ready the property " << propertyName << " from the settings.txt file";
        throw std::exception();
    }
}