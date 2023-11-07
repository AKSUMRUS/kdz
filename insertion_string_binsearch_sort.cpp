#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <string>

void insertionSort(std::vector<std::string>& v) {
    int n = v.size();

    for(int i = 1; i < n; ++i) {
        std::string x = v[i];
        int l = -1,r = i;
        while (l+1 < r) {
            int m = (l+r)>>1;
            if(v[m] > v[i]) {
                r = m;
            } else {
                l = m;
            }
        }
        for(int j = i; j > r; --j) {
            v[j] = v[j-1];
        }
        v[r] = x;
    }
}

int main() {
    freopen("build/tests.txt", "r", stdin);
    freopen("build/insertion_string_binsearch_sort_results", "w", stdout);

    int t,d;
    std::cin >> t >> d;

    while (t--) {
        int b = d;
        while (b--) {
            int n;

            std::cin >> n;

            std::vector <std::string> v(n);

            for (auto &x: v) {
                std::cin >> x;
            }

            std::time_t startTime = std::clock();

            insertionSort(v);

            std::time_t endTime = std::clock();

            std::cout << ((double) endTime - startTime) / CLOCKS_PER_SEC << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
