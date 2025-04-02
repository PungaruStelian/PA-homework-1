#ifndef WALSH_H_
#define WALSH_H_

/**
 * Computes the value at the (x, y) position in the Walsh matrix of order n by counting the number of times the indices are in bottom right quadrants.
 * @param n The order of the Walsh matrix (must be a power of 2).
 * @param x The row index (1-based).
 * @param y The column index (1-based).
 * @return The value at the (x, y) position in the Walsh matrix of order n.
 */
int walsh(int n, int x, int y);

#endif  // WALSH_H_
