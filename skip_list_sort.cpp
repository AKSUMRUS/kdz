#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>
#include <stdio.h>

int main() {
    freopen("build/tests.txt", "r", stdin);
    freopen("build/merge_sort_results", "w", stdout);

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

        // Sort 

        std::time_t endTime = std::clock();

        std::cout << ((double) endTime - startTime)/CLOCKS_PER_SEC  << "\n";

    }
    return 0;
}
