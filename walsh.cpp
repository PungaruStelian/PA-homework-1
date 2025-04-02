#include <iostream>
#include <fstream>
#include "./walsh.h"

int walsh(int n, int x, int y) {
    int cnt = 0;
    while (n > 1) {
        // bottom right, conut changes that must be made
        if (x > n / 2 && y > n / 2) {
            x -= n / 2;
            y -= n / 2;
            cnt ++;
        // bring indices to new matrix
        } else {
            if (x > n / 2)
                x -= n / 2;
            if (y > n / 2)
                y -= n / 2;
        }
        // new matrix size
        n /= 2;
    }
    return cnt % 2;
}

int main() {
    std::ifstream fin("walsh.in");
    std::ofstream fout("walsh.out");
    int N, K;
    fin >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        fin >> x >> y;
        fout << walsh(N, x, y) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
