#ifndef REGELE_H_
#define REGELE_H_

#include <vector>

/**
 * Performs binary search to find the maximum number of cities that can be selected
 * such that the sum of distances does not exceed M.
 * 
 * @param left The lower bound for binary search
 * @param right The upper bound for binary search
 * @param max_sum A vector containing the maximum sum of distances for each possible number of selected cities
 * @param M The maximum allowed sum of distances
 * @return The maximum number of cities that can be selected
 */
int binary_search(int left, int right, const std::vector<int>& max_sum, int M);

/**
 * Calculates the maximum sum of distances for a given number of cities and their coordinates.
 * 
 * @param N The number of cities
 * @param coord A vector containing the coordinates of the cities
 * @return A vector containing the maximum sum of distances for each possible number of selected cities
 */
std::vector<int> calculate_max_sum(int N, const std::vector<int>& coord);

#endif  // REGELE_H_
