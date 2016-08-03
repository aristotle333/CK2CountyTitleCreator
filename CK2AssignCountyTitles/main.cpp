#include <cctype>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "readSettings.h"
#include "provinceNameToID.h"
#include "titleCreator.h"
using std::string;
using std::stringstream;
using std::unordered_map;
using std::unordered_set;

unordered_set<int> parseProvincesRequiringTitles(const string& provincesRequiringTitles);
bool is_number(const string& s);

int main() {

    settingVals setVals = readSettings();

    //string provincesPath = setVals.provincesPath;
    //string titlesPath = setVals.titlesPath;
    //string provincesRequiringTitles = setVals.provincesRequiringTitles;

    unordered_map<string, int> provinceNameToIDMap = createProvinceNameToIDMap(setVals.provincesPath);
    unordered_set<int> provincesToMakeTitles = parseProvincesRequiringTitles(setVals.provincesRequiringTitles);

    CreateTitles(setVals, provinceNameToIDMap, provincesToMakeTitles);

    std::cout << "Successfully created titles for provinces: " << setVals.provincesRequiringTitles << "\n\n";

    system("pause");

    return 0;
}

unordered_set<int> parseProvincesRequiringTitles(const string& provincesRequiringTitles) {
    unordered_set<int> set;
    stringstream ss;
    ss << provincesRequiringTitles;
    string str;
    while (ss >> str) {
        // Single province ID
        if (is_number(str)) {
            set.emplace(std::stoi(str));
        }
        // Province ID range
        else {
            stringstream tempSS;
            tempSS << str;
            int min, max; char dummy;
            tempSS >> min >> dummy >> max;
            for (int i = min; i <= max; ++i) {
                set.emplace(i);
            }
        }
    }
    return set;
}

bool is_number(const string& s) {
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) {
        ++it;
    }
    return !s.empty() && it == s.end();
}