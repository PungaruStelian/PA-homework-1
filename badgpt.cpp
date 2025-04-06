#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "./badgpt.h"

std::ifstream fin("badgpt.in");
std::ofstream fout("badgpt.out");

#define MOD 1000000007

void multiply(std::vector<std::vector<long>> &m1,
    std::vector<std::vector<long>> &m2) {
    long a = ((m1[0][0] * m2[0][0]) % MOD + (m1[0][1] * m2[1][0]) % MOD) % MOD;
    long b = ((m1[0][0] * m2[0][1]) % MOD + (m1[0][1] * m2[1][1]) % MOD) % MOD;
    long c = ((m1[1][0] * m2[0][0]) % MOD + (m1[1][1] * m2[1][0]) % MOD) % MOD;
    long d = ((m1[1][0] * m2[0][1]) % MOD + (m1[1][1] * m2[1][1]) % MOD) % MOD;
    m1[0][0] = a;
    m1[0][1] = b;
    m1[1][0] = c;
    m1[1][1] = d;
}

void power(std::vector<std::vector<long>> &m, long n) {
    if (n == 1)
        return;
    power(m, n / 2);
    multiply(m, m);
    if (n % 2 != 0) {
        std::vector<std::vector<long>> i = {{1, 1}, {1, 0}};
        multiply(m, i);
    }
}

int fib(long n) {
    std::vector<std::vector<long>> m = {{1, 1}, {1, 0}};
    power(m, n);
    return m[0][0];
}

int main() {
    // number as string from the string read from the file
    std::string str = "";
    // current letter
    char c;
    // current ascii code of the character read from the file
    int n;
    // nr is the number form the string read
    // nums is the answer to the problem
    long nr, nums = 1;
    n = fin.get();
    // EOF = -1 (end of file)
    if (n != EOF)
        c = (char)n;
    while (n != EOF) {
        if (n >= 'a' && n <= 'z') {
            if ((c == 'n' || c == 'u') && !str.empty()) {
                nr = std::stol(str);
                nums = (nums * fib(nr)) % MOD;
            }
            c = (char)n;
            str = "";
        } else {
            str += (char)n;
        }
        n = fin.get();
    }
    if ((c == 'n' || c == 'u') && !str.empty()) {
        nr = std::stol(str);
        nums = (nums * fib(nr)) % MOD;
    }
    fout << nums;
    fin.close();
    fout.close();
    return 0;
}
