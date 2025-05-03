// Реализуйте бинарное дерево поиска для целых чисел. Выведите единственное число — высоту получившегося дерева.

#include <iostream>
#include <vector>
#include <algorithm>

class BST {
    struct Node {
        int data;
        Node *l = nullptr, *r = nullptr;
        Node(int data): data(data) {};
    } *root = nullptr;

    void Insert(Node *&n, int data) {
        if (!n) {
            n = new Node(data);
            return;
        }
        if (data == n->data) return;
        if (data < n->data) Insert(n->l, data);
        else Insert(n->r, data);
    }

    int GetHeight(Node* n) {
        if (!n) return 0;
        return 1 + std::max(GetHeight(n->l), GetHeight(n->r));
    }

public:
    void Insert(int data) {
        Insert(root, data);
    }

    int Height() {
        return GetHeight(root);
    }
};

int main() {
    BST bst;
    int elem;
    std::cin >> elem;
    while (elem != 0) {
        bst.Insert(elem);
        std::cin >> elem;
    }
    std::cout << bst.Height();
    return 0;
}
