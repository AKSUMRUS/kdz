#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>

void insertionSort(std::vector<int>& v) {
    int n = v.size();

    for(int i = 1; i < n; ++i) {
        int x = v[i];
        int j = i;
        while (j > 0 && v[j-1] > x) {
            v[j] = v[j-1];
            --j;
        }
        v[j] = x;
    }
}

int main() {
    freopen("build/tests.txt", "r", stdin);
    freopen("build/insertion_sort_results", "w", stdout);

    int t;
    std::cin >> t;

    while (t--) {
        int n;

        std::cin >> n;

        std::vector<int> v(n);

        for(auto& x: v) {
            std::cin >> x;
        }

        std::time_t startTime = std::clock();

        insertionSort(v);

        std::time_t endTime = std::clock();

        std::cout << ((double) endTime - startTime)/CLOCKS_PER_SEC  << "\n";
    }
    return 0;
}
