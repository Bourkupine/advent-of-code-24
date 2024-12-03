#include "aoc_strings.h"

std::vector<std::string> 
splitString(std::string str, std::string delimiter) {
    std::vector<std::string> ret;
    size_t i = 0;
    while ((i = str.find(delimiter)) != std::string::npos) {
        ret.push_back(str.substr(0, i));
        str.erase(0, i + delimiter.length());
    }
    ret.push_back(str); // add the remaining substring
    return ret;
}
