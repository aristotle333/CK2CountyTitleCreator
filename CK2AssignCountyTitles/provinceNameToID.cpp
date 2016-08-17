#include "provinceNameToID.h"

unordered_map<string, int> createProvinceNameToIDMap(string provincesPath) {
    DIR *dir;
    struct dirent *ent;
    unordered_map<string, int> provinceNameToID;
    if ((dir = opendir(provincesPath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            stringstream ss;
            int provinceID; string dummy, provinceName, provinceNameFull;
            ss << ent->d_name;
            
            if (ss >> provinceID >> dummy) {
                while (ss >> provinceName) {
                    provinceNameFull += provinceName + "_";
                }
                provinceNameFull = provinceNameFull.substr(0, provinceNameFull.find("."));
                std::transform(provinceNameFull.begin(), provinceNameFull.end(), provinceNameFull.begin(), ::tolower);
                if (!provinceNameToID.count(provinceNameFull)) {
                    provinceNameToID.emplace(provinceNameFull, provinceID);
                }
                else {
                    std::cerr << "Duplicate province ID detected for the province " << provinceNameFull << " with ID " << provinceID << "\n";
                    throw std::exception();
                }
            }
        }
        closedir(dir);
    }
    else {
        std::cerr << "Unable to parse directory";
        throw std::exception();
    }
    return provinceNameToID;
}