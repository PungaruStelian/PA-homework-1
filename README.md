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

- Time complexity: O(N * log(sum(G)))
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

- Time complexity: O(K * log(N))
- Space complexity: O(K)

### BadGPT

#### Description

Gigel decided to use the new tool StatementGPT to generate statements for his assignments at Politehnica. This tool does not necessarily generate interesting statements, but by using a new extension (created by himself) called GPT2PDF, it takes the statement and converts it into a PDF format, making it ready for publication.

Gigel's problem is that his extension does not transform the statement into a PDF by copying the text, but rather by creating an image based on the original text. However, this tool fails to correctly process the letters "m" and "w." The letter "m" will appear in the statement as "nn," while the letter "w" will appear as "uu" (since StatementGPT prefers English). For example, if the sequence "anna" appears in the PDF statement, then the original sequence could have been either "anna" or "ama."

Gigel is curious to find out whether his extension is reliable or not. He wants to determine how many distinct strings could have originally formed the statement based on the character sequence in the PDF. Afraid of a potentially large number of possibilities, the result will be displayed modulo 10^9 + 7 (this way, the result might be 1, and Gigel will be satisfied).

#### Input

The input file badgpt.in will contain a single line with a compressed character string in the form l1n1l2n2 ..., where the sequence l_i n_i indicates that the letter l_i appears n_i times in a row.
It is guaranteed that the same letter will not appear in two consecutive positions. For example, we cannot have the encoded string u3u4. This will be represented as u7.

#### Output

The output file badgpt.out will contain a single line with the number of distinct strings that could have originally formed the statement, modulo 10^9 + 7.

#### Restrictions

- 1 ≤ l_i, n_i ≤ 10^18
- 1 ≤ G ≤ 10^5; where G is the number of compressed groups. A compressed group represents a pair l_i n_i indicating that the letter l_i will appear n_i times in a row.

#### Testing

- The source that account, holds the function, must be called ̆A: badgpt.c, badgpt.cpp or badgpt.java.

#### Example

| badgpt.in       | badgpt.out | Explanation |
|-----------------|------------|-------------|
|a1c3n2 | 2 | Codificarea corespunde s,irului acccnn. <br> Exist ̆a 2 s,iruri init,iale posibile: acccnn s,i acccm. |

#### Implementation

We observe that only when we have sequences consisting exclusively of the letters "n" or "u" do we have multiple reconstruction possibilities, as these could originate either from the original "n"/"u" characters or from the transformations "m" → "nn" and "w" → "uu". In contrast, all other characters remain unchanged and contribute exactly one unique possibility to the count.

The essence of the problem is to determine the number of distinct representations of the original sequence, considering that each sequence of "nn" or "uu" could have either come from an identical sequence or from an equivalent "m"/"w". This process leads to a recurrence relation of the form:

- dp[i] = dp[i-1] + dp[i-2]

where:

- dp[i-1] represents the number of ways we can obtain the sequence up to position i-1, assuming the last character is an original "n" or "u".

- dp[i-2] represents the number of ways we can obtain the sequence up to position i-2, assuming the last two characters are "nn" or "uu" and originate from an "m"/"w".

Thus, the solution requires computing the nth Fibonacci number, which can be efficiently achieved in O(log n) using matrix exponentiation.

a = number of occurrences of n or u from input
b = number that follows after the letter u or n of the input

- Time complexity: O(a * log(b))
- Space complexity: O(size(input) + log(b))

### REGELE (The King)

#### Description

After all the trials he went through during the PA assignments, Gigel became the wisest man and was chosen as the king of the Gigeland kingdom. At this moment, the kingdom is facing a problem that needs immediate resolution.
The kingdom has a commercial network consisting of N cities placed along a line. City i is located at coordinate coord[i]. A city can trade only with its neighboring cities (the leftmost and rightmost cities have only one neighbor).
A trade route between two cities is considered active if we can allocate a number of merchants equal to the distance between those two cities. If a route is active, it is active for both cities it connects.
A city is considered active if both of its trade routes are active. Unfortunately, the kingdom doesn't have enough merchants to handle all the trade routes.
Since the number of merchants available in the kingdom can increase or decrease each day, Gigel wants to answer Q questions of the form:
Given M available merchants, what is the maximum number X such that, no matter how we choose X cities, the available merchants can be distributed across the trade routes in such a way that all X cities are commercially active?

#### Input

- On the first line of the file regele.in is N, the number of cities.
- On the second line are N numbers, representing the coordinates of the cities, separated by spaces, sorted in ascending order.
- On the third line is Q, the number of queries.
- On the following Q lines, there is a number M, representing the number of available merchants.

#### Output
- In the file regele.out, there will be Q lines, each containing a single number representing the maximum X that satisfies the property described in the statement.

#### Restrictions
- 1 ≤ Q ≤ 5*10^5
- 1 ≤ N ≤ 2000
- 1 ≤ coord[i] ≤ 10^9

#### Testing
- The source that account, holds the function, must be called ̆A: regele.c, regele.cpp or Regele.java.

#### Example
| regele.in       | regele.out | Explanation |
|-----------------|------------|-------------|
| 6 <br> 2 5 10 12 17 19 <br> 3 <br> 15 <br> 10 <br> 20 | 2 <br> 1 <br> 6 | 2 → if X were 3, to activate the cities at positions 5, 12, and 17, 17 merchants are needed. Any combination of 2 cities can be activated using 15 merchants. <br> 1 → any single city can be activated if we have 10 merchants. Simultaneous activation of the cities at coordinates 5 and 17 is not possible with 10 merchants (15 are needed). <br> 6 → to activate all cities, 17 merchants are required.

## Implementation
We precompute a result vector that stores the maximum total cost (merchant count) required to activate the most expensive combinations of cities for each possible number of selected cities. curr_[k] and prev_[k] are used to recursively compute the maximum cost for selecting k active cities from the first i cities, based on whether or not the i-th city is included. The maximum cost at step i is the greater between the cost including the current city (which means both of its routes must be active), or the cost excluding it (taking the best result from the previous step). In the end, we perform a binary search to find the largest number of cities X such that the cost to activate any X cities is less than or equal to M (available merchants). The number of cities X is the index in the result vector.

- Time complexity: O(N^2 + Q * log(N))
- Space complexity: O(N + Q)