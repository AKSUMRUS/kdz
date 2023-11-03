#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>
#include <stdio.h>

std::vector<int> mergeSort(std::vector<int>& v, int leftBound, int rightBound) {
    int              n = rightBound-leftBound+1;
    std::vector<int> sortedVector(n);

    if(n == 1) {
        sortedVector[0] = v[leftBound];
    } else {
        int m = (leftBound+rightBound) >> 1;
        int iterator = 0;
        int iterator1 = 0;
        int iterator2 = 0;

        std::vector<int> vector1 = mergeSort(v, leftBound, m);
        std::vector<int> vector2 = mergeSort(v, m+1, rightBound);

        while (iterator1 < vector1.size() || iterator2 < vector2.size()) {
            if(iterator1 < vector1.size() && iterator2 < vector2.size()) {
                if(vector1[iterator1] < vector2[iterator2]) {
                    sortedVector[iterator++] = vector1[iterator1++];
                } else {
                    sortedVector[iterator++] = vector2[iterator2++];
                }
            }
            else if(iterator1 < vector1.size()) {
                sortedVector[iterator++] = vector1[iterator1++];
            } else {
                sortedVector[iterator++] = vector2[iterator2++];
            }
        }
    }

    return sortedVector;
}

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

        std::vector<int> ans = mergeSort(v, 0, n-1);

        std::time_t endTime = std::clock();

        std::cout << ((double) endTime - startTime)/CLOCKS_PER_SEC  << "\n";

    }
    return 0;
}
