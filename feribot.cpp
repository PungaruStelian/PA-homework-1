#include <iostream>
#include <fstream>
#include <vector>
#include "./feribot.h"

std::ifstream fin("feribot.in");
std::ofstream fout("feribot.out");

void read(int &N, int &K, std::vector<long> &G, long &maxElem, long &sum) {
    fin >> N >> K;
    // only memory allocation, no initialization => more efficient
    G.reserve(N);
    for (int i = 0; i < N; i++) {
        fin >> G[i];
        sum += G[i];
        if (G[i] > maxElem) {
            maxElem = G[i];
        }
    }
}

bool check(long mid, int N, int K, std::vector<long> &G) {
    long sum = 0;
    int count = 1;
    for (int i = 0; i < N; i++) {
        if (G[i] > mid) {
            return false;
        }
        sum += G[i];
        if (sum > mid) {
            count++;
            sum = G[i];
        }
    }
    if (count > K)
        return false;
    return true;
}

long binarySearch(long left, long right, int N, int K, std::vector<long> &G) {
    long result = right;
    while (left <= right) {
        long mid = (left + right) / 2;
        if (check(mid, N, K, G)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

void solve() {
    int N, K;
    long maxElem = 0, sum = 0;
    std::vector<long> G;
    read(N, K, G, maxElem, sum);
    fout << binarySearch(maxElem, sum, N, K, G);
    fin.close();
    fout.close();
}

int main() {
    solve();
    return 0;
}
