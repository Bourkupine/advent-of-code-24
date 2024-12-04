#ifndef _AOC_VECTORS_H_
#define _AOC_VECTORS_H_

#include <vector>
#include <string>

/* Converts a vector of strings to a vector of ints
 * Returns a vector of type int
*/
std::vector<int>
vectorSTOI(std::vector<std::string> input);

/* Compares 2 vectors
 * Returns:
 * 0 if the same
 * position (+1) if not the same
*/
int
compare_vectors(std::vector<int> vec1, std::vector<int> vec2);

#endif