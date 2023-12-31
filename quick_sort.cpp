#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <random>
#include <chrono>

std::mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

int divide(std::vector<int> &v, int l, int r) {
    int pivot = v[rng() % (r - l + 1) + l];
    int i = l;
    int j = r;
    while (i <= j) {
        while (v[i] < pivot) {
            ++i;
        }
        while (v[j] > pivot) {
            --j;
        }
        if (i <= j) {
            std::swap(v[i], v[j]);
            --j;
            ++i;
        }
    }
    return j;
}

void quickSort(std::vector<int> &v, int l, int r) {
    if (l < r) {
        int index = divide(v, l, r);

        quickSort(v, l, index);
        quickSort(v, index + 1, r);
    }
}

int main() {
    freopen("build/tests.txt", "r", stdin);
    freopen("build/quick_sort_results", "w", stdout);

    int t;
    std::cin >> t;

    while (t--) {

        int n;

        std::cin >> n;

        std::vector<int> v(n);

        for (auto &x: v) {
            std::cin >> x;
        }

        std::time_t startTime = std::clock();

        quickSort(v, 0, n - 1);

        std::time_t endTime = std::clock();

        std::cout << ((double) endTime - startTime) / CLOCKS_PER_SEC << "\n";

    }
    return 0;
}
