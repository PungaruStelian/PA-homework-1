#ifndef BADGPT_H_
#define BADGPT_H_

#include <vector>

/**
 * Multiplies two 2x2 matrices m1 and m2 and stores the result in m1.
 * 
 * @param m1 The first matrix to be multiplied.
 * @param m2 The second matrix to be multiplied.
 */
void multiply(std::vector<std::vector<long>> &m1,
    std::vector<std::vector<long>> &m2);

/**
 * Raises the matrix m to the power of n in logarithmic time. In inversed order of recursion because of the rest of the exponent's divisions to 2: if exponent is odd, the result is (...) * m.
 * 
 * @param m The matrix to be raised to a power.
 * @param n The exponent to which the matrix is raised.
 */
void power(std::vector<std::vector<long>> &m, long n);


/**
 * Computes the nth Fibonacci number using matrix exponentiation.
 * 
 * @param n The index of the Fibonacci number to compute.
 * @return The nth Fibonacci number.
 */
int fib(long n);

#endif  // BADGPT_H_
