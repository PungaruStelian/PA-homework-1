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
|---------------|----------|-------------|
| 10 5 <br> 3 4 2 1 6 7 1 2 2 3 | 8        | On the first ferry, the first two cars enter (3+4=7).<br>On the second one, the next two (2+1=3).<br>On the third, the next car (6).<br>On the fourth, the next two (7+1=8).<br>On the last ferry, the last three cars (2+2+3=7). |

#### Implementation
We do the binary search on the possible range for the maximum weight of a ferry: [the maximum vector element, the sum of the elements in the vector] => [max (G), sum (G)].
At every step, we check if we can put in every k feribot the maximum chosen weight. We half the interval and f we found a solution we go in the lower half, otherwise to the upper one.
We keep the last solution found being the smallest.

- Time complexity: O(N log sum(G))
- Space complexity: O(N)