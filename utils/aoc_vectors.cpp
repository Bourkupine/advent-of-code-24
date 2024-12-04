#include "aoc_vectors.h"

std::vector<int>
vectorSTOI(std::vector<std::string> input) {
    std::vector<int> ret;
    for(int i = 0; i < input.size(); i++) {
        ret.push_back(atoi(input[i].c_str()));
    }
    return ret;
}

int
compare_vectors(std::vector<int> vec1, std::vector<int> vec2) {
    for (int i = 0; i < vec1.size(); i++) {
        if (vec1[i] != vec2[i])
            return i+1;
    }
    return 0;
}
