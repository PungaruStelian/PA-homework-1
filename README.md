# Assignment 1 - Algorithm Design

## Introduction

This repository contains the implementation of Assignment 1 for the Algorithm Design course. The assignment focuses on applying various algorithmic techniques to solve practical problems efficiently. Each problem requires careful analysis and optimization to meet the given constraints.

## Problems

### Feribot (Ferry)

#### Description

K ferrys must transport a series of cars(N) across a river. The ferry has a maximum weight capacity that it can carry in a single trip. Each car has its own weight(G), and the ferry can make multiple trips to transport all cars. However, the ferry must maintain the original order of cars during transportation.

The goal is to determine the minimum possible value for the ferry's weight capacity that allows all cars to be transported, while respecting the order constraint.

#### Input
- In feribot.in
- On the first line: two integers N and K representing the number of cars and the maximum number of trips the ferry can make.
- On the second line: N integers representing the weights of each car.

#### Output
- In feribot.out
- A single integer representing the minimum weight capacity of the ferry needed to transport all cars.

#### Restrictions
- (1 ≤ K ≤ N ≤ 10^5)
- (1 ≤ Gᵢ ≤ 10^12)

#### Testing
- The source that account, holds the function, must be called ̆A: feribot.c, feribot.cpp or feribot.java.

#### Example
| ferry.in       | ferry.out | Explanation |
|----------------|-----------|-------------|
| 10 5 <br> 3 4 2 1 6 7 1 2 2 3 | 8        | On the first ferry, the first two cars enter (3+4=7).<br>On the second one, the next two (2+1=3).<br>On the third, the next car (6).<br>On the fourth, the next two (7+1=8).<br>On the last ferry, the last three cars (2+2+3=7). |

#### Implementation
We do the binary search on the possible range for the maximum weight of a ferry: [the maximum vector element, the sum of the elements in the vector] => [max (G), sum (G)].
At every step, we check if we can put in every k feribot the maximum chosen weight. We half the interval and f we found a solution we go in the lower half, otherwise to the upper one.
We keep the last solution found being the smallest.

- Time complexity: O(N log sum(G))
- Space complexity: O(N)

### Walsh

#### Description

Gigel wants to implement a secret communication channel. After conducting some research, he discovered that a good encryption method is using **Walsh Tables**. These tables take the form of a square matrix of dimensions (N times N), where (N) is a power of 2. 

We denote:
- (W_1) as the table of size (1 × 1),
- (W_2) as the table of size (2 × 2),
- (W_4) as the table of size (4 × 4),  
- and so on.

Walsh Tables has generated according to the following:
W_1 = [0] W_2n = [[W_n | W_n] [W_n | !W_n]]
where! w_n will contain the elements in w_n denied (1 becomes 0, and 0 becomes 1).

With this table, Gigel asks: For K pairs (X, Y): What value is in the Walsh table at the X line, the column
y? (for example, for: x = 3 s, i y = 2 = ⇒ 0)

#### Input
- In walsh.in
- On the first line: two integers N and K representing the size of the Walsh table and the number of queries.
- On the next K lines: two integers X and Y representing the coordinates of the Walsh table.
- The Walsh table is indexed starting from 1.

#### Output
- In walsh.out
- K lines, each containing the value at the specified coordinates in the Walsh table.
- The output should be in the same order as the input queries.

#### Restrictions

- (1 ≤ K ≤ 10^5)
- (1 ≤ X, Y ≤ N ≤ 2^30)

#### Testing
- The source that account, holds the function, must be called ̆A: walsh.c, walsh.cpp or walsh.java.

#### Example

| walsh.in       | walsh.out | Explanation |
|----------------|-----------|-------------|
| 4 5 <br> 1 3 <br> 4 2 <br> 3 3 <br> 1 2 <br> 2 1 | 0 <br> 1 <br> 1 <br> 0 <br> 0 | On line 1, column 3 the value is 0 <br> On line 4, column 2 the value is 1 <br> On line 3, column 3 the value is 1 <br> On line 1, column 2 the value is 0 <br> On line 2, column 1 the value is 0 |

#### Implementation

Since all submatrices, except for the one in the bottom right, retain their terms, we are interested in how many times the element appears in these submatrices to invert its value. When we reach W_2 with the element still in the bottom right, the value is 1, and recursively it alternates back to 0. Every time the element is in another submatrix, it retains the value it had before, which is the value from the minimal unchanged matrix.

- Time complexity: O(log(N))
- Space complexity: O(K)