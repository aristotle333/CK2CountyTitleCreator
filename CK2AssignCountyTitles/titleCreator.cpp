#include "titleCreator.h"

void CreateTitles(const settingVals& setVal, const unordered_map<string, int>& provinceNameToIDMap, const unordered_set<int>& provinceReqTitles) {
DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(setVal.titlesPath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            string fileName = ent->d_name;
            if (fileName.size() > 1 && fileName[0] == 'c') {
                // Remove prefix and .txt
                fileName = fileName.substr(0, fileName.find("."));
                fileName = fileName.substr(2);
                auto iter = provinceNameToIDMap.find(fileName);
                if (iter != provinceNameToIDMap.end()) {
                    int provID = iter->second;
                    if (provinceReqTitles.count(provID)) {
                        // Province requires title
                        CreateTitle(setVal, ent, provID);
                    }
                }
                else {
                    std::cerr << "County name not found in the provinceNameToIDMap\n";
                }
            }
        }
        closedir(dir);
    }
    else {
        std::cerr << "Unable to parse directory";
        throw std::exception();
    }
}

void CreateTitle(const settingVals& setVal, const dirent* ent, int provID) {
    string inputFile = setVal.titlesPath + "\\" + ent->d_name;
    string outputFile = setVal.titlesPath + "\\" + "temp" + to_string(provID) + ".txt";
    ifstream in(inputFile);
    ofstream out(outputFile);
    string line;
    int bracketsLeftToSkip = setVal.numBracketsToSkip;

    // Copy original Title file
    while (getline(in, line)) {
        if (line == "}") {
            --bracketsLeftToSkip;
            if (bracketsLeftToSkip == 0) {
                out << line << "\n";
                break;
            }
        }
        out << line << "\n";
    }

    // Write the line of title
    out << setVal.titleHolderDate << "={\n" << "\tholder=" << provID * 100 << "\n}";
    in.close();
    out.close();

    if (_access_s(inputFile.c_str(), 0) == 0) {
        if (remove(inputFile.c_str()) != 0) {
            perror("Failed to delete file: ");
            throw std::exception();
        }
    }

    if (rename(outputFile.c_str(), inputFile.c_str()) != 0) {
        std::cerr << "Failed to ovewrite " << inputFile << "\n";
        throw std::exception();
    }
}