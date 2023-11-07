#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <random>
#include <unordered_map>
#include <chrono>

//std::mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

int maxDepth = 1;

bool flipCoin() {
    return rand()&1;
}

class SkipListNode {
public:
    int value;
    std::vector<SkipListNode *> next;

    SkipListNode(int value) : value(value), next(maxDepth+1, nullptr) {}
};

//if (root->next[depth] == nullptr) {
//if (depth == maxDepth) {
//root->next[depth] = new SkipListNode(value);
//return 1;
//} else {
//bool res = insert(root, value, depth + 1);
//if(res) {
//res = flipCoin();
//}
////            std::cout << value << " " << depth << " " << res << "\n";
//if (res) {
//root->next[depth] = root->next[depth + 1];
//root->next[depth]->next[depth] = nullptr;
//}
//
//return res;
//}
//} else if (root->next[depth]->value <= value) {
//return insert(root->next[depth], value);
//} else if (root->next[depth]->value > value) {
//if (depth == maxDepth) {
//SkipListNode *newNode = new SkipListNode(value);
//newNode->next[depth] = root->next[depth];
//root->next[depth] = newNode;
//return 1;
//} else {
//bool res = insert(root, value, depth + 1);
//if(res) {
//res = flipCoin();
//}
////            std::cout << value << " " << depth << " " << res << "\n";
//if (res) {
//SkipListNode *next = root->next[depth];
//root->next[depth] = root->next[depth + 1];
//root->next[depth]->next[depth] = next;
//}
//
//return res;
//}
//}

SkipListNode* insert(SkipListNode *root, int value, int depth = 0) {
    if(!root->next[depth]) {
        if (depth == maxDepth) {
            SkipListNode *newNode = new SkipListNode(value);
            root->next[depth] = newNode;
            return newNode;
        } else {
            SkipListNode *newNode = insert(root, value, depth + 1);
            bool res = false;
            if (newNode) {
                res = flipCoin();
            }
            if (res) {
                root->next[depth] = newNode;
                return newNode;
            } else {
                return nullptr;
            }
        }
    } else if(value >= root->next[depth]->value) {
        return insert(root->next[depth], value, depth);
    } else if(value < root->next[depth]->value) {
        if(depth == maxDepth) {
            SkipListNode* newNode = new SkipListNode(value);
            newNode->next[depth] = root->next[depth];
            root->next[depth] = newNode;
            return newNode;
        } else {
            SkipListNode* newNode = insert(root, value, depth+1);
            bool res = false;
            if (newNode) {
                res = flipCoin();
            }
            if (res) {
                newNode->next[depth] = root->next[depth];
                root->next[depth] = newNode;
                return newNode;
            } else {
                return nullptr;
            }
        }
    }

    return nullptr;
}

int main() {
    freopen("build/tests.txt", "r", stdin);
    freopen("build/skip_list_sort_results", "w", stdout);

    srand(time(0));

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

        SkipListNode *root = new SkipListNode(0);

        int x;
        for (int i = 0; i < n; ++i) {
            std::cin >> x;
            insert(root, x);
        }

        std::time_t endTime = std::clock();

        //        Cout the sorted array, answer is in i = maxDepth
//        std::cout << maxDepth << "\n";
//        for (int i = 0; i <= maxDepth; ++i) {
//            SkipListNode *a = root;
//            std::cout << "? ";
//            while (a) {
//                a = a->next[i];
//                if (a) {
//                    std::cout << a->value << " ";
//                }
//            }
//            std::cout << "\n";
//        }

        std::cout << ((double) endTime - startTime) / CLOCKS_PER_SEC << "\n";

    }
    return 0;
}
