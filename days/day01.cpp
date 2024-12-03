#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <chrono>
#include <map>

#include "../utils/aoc_strings.h"

using namespace std;

int
part01(vector<int> list1, vector<int> list2) {
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    int total = 0;
    for(int i = 0; i < list1.size(); i++) {
        total += abs(list1[i] - list2[i]);
    }

    return total;
}

int
part02(vector<int> list1, vector<int> list2) {
    unordered_map<int, int> mapping;
    int total = 0;

    for(int i = 0; i < list2.size(); i++) {
        int n = list2[i];
        if (mapping.count(n) == 0) {
            mapping[n] = 1;
        }
        else {
            mapping[n] = (mapping[n]+1);
        }
    }

    for(int i = 0; i < list1.size(); i++) {
        total += list1[i] * mapping[list1[i]];
    }
    return total;

}

int
main() {

    string text;
    ifstream input("./inputs/day01.txt");
    vector<int> list1;
    vector<int> list2;

    while (getline(input, text)) {
        vector<string> nums = splitString(text, "   ");
        list1.push_back(stoi(nums[0]));
        list2.push_back(stoi(nums[1]));
    }

    int res1 = part01(list1, list2);
    int res2 = part02(list1, list2);

    cout << "Result 1: " << res1 << endl;
    cout << "Result 2: " << res2 << endl;

    input.close();
}