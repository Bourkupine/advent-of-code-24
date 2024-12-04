#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

#include "../utils/aoc_strings.h"
#include "../utils/aoc_vectors.h"

using namespace std;

/* Checks if a row is valid
 * Returns bool value based on if its safe
*/
bool
check_row(vector<int> row) {
    vector<int> copy = row;
    sort(copy.begin(), copy.end());
    vector<int> copy2 = copy;
    reverse(copy2.begin(), copy2.end());
    if (!(row == copy || row == copy2)) {
        return false;
    }

    for (int i = 1; i < row.size(); i++) {
        int diff = abs(row[i-1] - row[i]);
        if (diff > 3 || diff < 1) {
            return false;
        }
    }
    return true;
}
/*
safe if:
- all increasing/decreasing
- differ by 1-3
return the amount of safes
*/

int
part01(vector<vector<int>> input) {
    int total = 0;
    for (vector<int> report : input) {
        // First check if vector is increasing/decreasing
        vector<int> copy = report;
        sort(copy.begin(), copy.end());
        vector<int> copy2 = copy;
        reverse(copy2.begin(), copy2.end());
        if (!(report == copy || report == copy2)) {
            continue;
        }
        // Check if it contains duplicates (unsafe)
        bool dupes = adjacent_find(report.begin(), report.end()) != report.end();
        if (dupes) {
            continue;
        }
        int prev = report[0]; // since we already checked for dupes, set prev to first element.
        bool unsafe = false;
        for (int level : report) {
            if (abs(level - prev) > 3) {
                unsafe = true;
                break;
            }
            prev = level;
        }
        if (!unsafe) {
            total++;
        }
    }
    return total;

}

int
part02(vector<vector<int>> input) {
    int total = 0;
    for (vector<int> report : input) {
        if (check_row(report)) {
            total++;
            continue;
        }
        for (int i = 0; i < report.size(); i++) {
            vector<int> temp = report;
            temp.erase(temp.begin() + i);
            if (check_row(temp)) {
                total++;
                break;
            }
        }
    }
    return total;
}


int
main() {

    string text;
    ifstream input("./inputs/day02.txt");

    vector<vector<int>> vec;

    while (getline(input, text)) {
        vector<string> line = splitString(text, " ");
        vec.push_back(vectorSTOI(line));
    }

    int res1 = part01(vec);
    int res2 = part02(vec);

    cout << "Result 1: " << res1 << endl;
    cout << "Result 2: " << res2 << endl;

    input.close();
}