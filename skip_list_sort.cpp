#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <random>

std::mt19937 rnd(time(0));

int maxDepth = 0;

class SkipListNode {
    public:
        int value;
        std::vector<SkipListNode*> next;

        SkipListNode(int value) : value(value)  {
            next.assign(maxDepth+1, nullptr);
        }
};

int flipCoin() {
    return rnd()%2;
}

int insert(SkipListNode* root, int value, int depth = 0) {
    if(root->next[depth] == nullptr) {
        if(depth == maxDepth) {
            root->next[depth] = new SkipListNode(value);
            // ...
            return 1;
        } else {
            bool res = insert(root, value, depth+1);
            res &= flipCoin();
            if(res) {
                SkipListNode* next = root->next[depth];
                root->next[depth] = root->next[depth+1];
                root->next[depth]->next[depth] = next;
            }

            return res;
        }
    } else if(root->next[depth]->value <= value) {
        insert(root->next[depth], value);
    } else if(root->next[depth]->value > value) {
        if(depth == maxDepth) {
            SkipListNode* newNode = new SkipListNode(value);
            newNode->next[depth] = root->next[depth];
            root->next[depth] = newNode;
            return 1;
        } else {
            bool res = insert(root, value, depth+1);
            res &= flipCoin();
            if(res) {
                SkipListNode* next = root->next[depth];
                root->next[depth] = root->next[depth+1];
                root->next[depth]->next[depth] = next;
            }

            return res;
        }
    }

    return 0;
}

int main() {
    freopen("build/tests.txt", "r", stdin);
    freopen("build/skip_list_sort_results", "w", stdout);

    int t;
    std::cin >> t;

    while (t--) {

        int n;

        std::cin >> n;

        std::time_t startTime = std::clock();
        // get max depth (log2 n)
        int m = n;
        while (m > 1) {
            m >>= 1;
            ++maxDepth;
        }

        SkipListNode* root = nullptr;

        for(int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            if(i == 0) {
                root = new SkipListNode(x);
            } else if(root->value > x) {
                SkipListNode* newRoot = new SkipListNode(x);
                for(int j = 0;j <= maxDepth; ++j) {
                    newRoot->next[j] = root;
                }
                root = newRoot;
            } else {
                insert(root, x);
            }
        }

        std::time_t endTime = std::clock();

        std::cout << ((double) endTime - startTime)/CLOCKS_PER_SEC  << "\n";

    }
    return 0;
}
