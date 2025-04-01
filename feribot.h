#ifndef FERIBOT_H_
#define FERIBOT_H_

#include <vector>

/**
 * Reads input data from the feribot.in file.
 * 
 * @param N Reference to variable storing the number of cars
 * @param K Reference to variable storing the number of ferries
 * @param G Reference to vector storing weights of cars
 * @param maxElem Reference to variable storing the maximum car weight
 * @param sum Reference to variable storing the sum of all car weights
 */
void read(int &N, int &K, std::vector<long> &G, long &maxElem, long &sum);

/**
 * Checks if it's possible to distribute cars among K ferries with maximum load of mid.
 * 
 * @param mid The maximum allowed weight per ferry
 * @param N The number of cars
 * @param K The number of ferries
 * @param G Reference to vector containing car weights
 * @return true if distribution is possible, false otherwise
 */
bool check(long mid, int N, int K, std::vector<long> &G);

/**
 * Performs binary search to find the minimum possible maximum ferry load.
 * 
 * @param left The lower bound for binary search (maximum car weight)
 * @param right The upper bound for binary search (sum of all car weights)
 * @param N The number of cars
 * @param K The number of ferries
 * @param G Reference to vector containing car weights
 * @return The minimum possible maximum ferry load
 */
long binarySearch(long left, long right, int N, int K, std::vector<long> &G);

/**
 * Solves the ferry problem by reading input, finding the solution, and writing output.
 */
void solve();

#endif  // FERIBOT_H_
