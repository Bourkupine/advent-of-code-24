#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <map>
#include <algorithm>

#include "../utils/aoc_strings.h"
#include "../utils/aoc_vectors.h"

using namespace std;


unordered_map<int, vector<int>> mapping;

bool
comp(int a, int b) {
    if (mapping.count(a)) {
        if (find(mapping[a].begin(), mapping[a].end(), b) != mapping[a].end()) {
            return false;
        }
    }
    return true;
}


int
part01(unordered_map<int, vector<int>> mapping, vector<vector<int>> pages) {
    int total = 0;
    for (vector<int> row : pages) {
        vector<int> seen;
        bool valid = true;
        for (int num : row) {
            if (mapping.count(num)) {
                seen.insert(seen.begin(), mapping[num].begin(), mapping[num].end());
            }
            if (find(seen.begin(), seen.end(), num) != seen.end()) {
                valid = false;
                break;
            }
        }
        if (valid) {
            int mid = row[row.size() / 2];
            total += mid;
        }
    }
    return total;
}

int
part02(unordered_map<int, vector<int>> mapping, vector<vector<int>> pages) {
    int total = 0;
    for (vector<int> row : pages) {
        vector<int> seen;
        bool valid = true;
        vector<int> copy = row;
        for (int num : row) {
            if (mapping.count(num)) {
                seen.insert(seen.begin(), mapping[num].begin(), mapping[num].end());
            }
            if (find(seen.begin(), seen.end(), num) != seen.end()) {
                valid = false;
            }
        }
        if (!valid) {
            sort(row.begin(), row.end(), comp);
            int mid = row[row.size() / 2];
            cout << mid << endl;
            total += mid;
        }
    }
    return total;
}


int
main() {

    string text;
    ifstream input("./inputs/day05.txt");

    vector<vector<int>> rules;
    vector<vector<int>> pages;

    bool rule = true;

    while (getline(input, text)) {
        if (text == "") {
            rule = false;
            continue;
        }
        if (rule) {
            rules.push_back(vectorSTOI(splitString(text, "|")));
        } else {
            pages.push_back(vectorSTOI(splitString(text, ",")));
        }
    }

    for (vector<int> rule : rules) {
        mapping[rule[1]].push_back(rule[0]);
    }


    int res1 = part01(mapping, pages);
    int res2 = part02(mapping, pages);

    cout << "Result 1: " << res1 << endl;
    cout << "Result 2: " << res2 << endl;

    input.close();
}