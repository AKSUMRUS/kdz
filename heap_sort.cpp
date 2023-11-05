#include <iostream>
#include <type_traits>
#include <vector>
#include <ctime>
#include <stdio.h>

void heapify(std::vector<int>& heap, int n, int i) {
    int root = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && heap[l] > heap[root]) {
        root = l;
    }

    if(r < n && heap[r] > heap[root]) {
        root = r;
    }

    if(root != i) {
        std::swap(heap[root], heap[i]);

        heapify(heap, n, root);
    }
}

void heapSort(std::vector<int>& v) {
    int n = v.size();
    
    for(int i = (n>>1) - 1; i >= 0; --i) {
        heapify(v, n, i);
    }

    for(int i = n-1; i >= 0; --i) { 
        std::swap(v[0], v[i]);

        heapify(v, i, 0);
    }
}

int main() {
    freopen("build/tests.txt", "r", stdin);
    freopen("build/heap_sort_results", "w", stdout);

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

        heapSort(v);

        std::time_t endTime = std::clock();

        std::cout << ((double) endTime - startTime)/CLOCKS_PER_SEC  << "\n";
    }
    return 0;
}
