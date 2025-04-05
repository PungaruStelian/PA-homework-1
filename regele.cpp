#include <iostream>
#include <fstream>
#include <vector>
#include "./regele.h"

int binary_search(int left, int right, const std::vector<int>& max_sum, int M) {
    int answer = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (max_sum[mid] <= M) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

std::vector<int> calculate_max_sum(int N, const std::vector<int>& coord) {
    std::vector<int> dist;
    for (int i = 0; i < N-1; ++i)
        dist.push_back(coord[i+1] - coord[i]);
    // prev_without[k] = maximum value when exactly k cities are selected from
    // the first (i-1) cities, and city (i-1) is NOT included in selection
    // prev_with[k] = maximum value when exactly k cities are selected from
    // the first (i-1) cities, and city (i-1) IS included in selection
    std::vector<int> prev_without(N+1, 0), prev_with(N+1, 0);
    for (int i = 0; i < N; ++i) {
        // Vectors for current DP state:
        // curr_without[k] = maximum value when exactly k cities are selected
        // from first i cities, and city i is NOT included in selection
        // curr_with[k] = maximum value when exactly k cities are selected
        // from first i cities, and city i IS included in selection
        // Initialize with 0 to calculate maximum values in the loop
        std::vector<int> curr_without(N+1, 0), curr_with(N+1, 0);
        int left = (i > 0) ? dist[i-1] : 0;
        int right = (i < N-1) ? dist[i] : 0;
        int interval = left + right;
        for (int k = 0; k < i; ++k) {
            // Add one more city to selection using
            // distance between adjacent cities
            curr_with[k+1] = prev_without[k] + interval;
            // Maximum of both possibilities for k selected cities
            curr_without[k] = std::max(prev_with[k], prev_without[k]);
        }
        prev_without = move(curr_without);
        prev_with = move(curr_with);
    }
    std::vector<int> max_sum(N+1);
    for (int k = 0; k <= N; ++k)
        max_sum[k] = std::max(prev_without[k], prev_with[k]);
    return max_sum;
}

int main() {
    std::ifstream fin("regele.in");
    std::ofstream fout("regele.out");
    int N;
    fin >> N;
    std::vector<int> coord(N);
    for (int i = 0; i < N; ++i)
        fin >> coord[i];
    std::vector<int> max_sum = calculate_max_sum(N, coord);
    int Q;
    fin >> Q;
    while (Q--) {
        int M;
        fin >> M;
        fout << binary_search(0, N, max_sum, M) << '\n';
    }
    return 0;
}
