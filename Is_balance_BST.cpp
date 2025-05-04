//Дерево называется сбалансированным, если для любой его вершины высота левого и правого поддерева для этой вершины различаются не более чем на 1.
// Определите, является ли дерево сбалансированным, выведите слово YES или NO.

#include <iostream>
#include <algorithm>
#include <cmath>

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
        if (n->data == data) return;
        if (data < n->data) Insert(n->l, data);
        else Insert(n->r, data);
    }

    int getHeight(Node *n) {
        if (!n) return 0;
        return (1 + std::max(getHeight(n->l), getHeight(n->r)));
    }

    bool checkBalance(Node *n) {
        if (!n) return true;
        if (std::abs(getHeight(n->l) - getHeight(n->r)) > 1) {
            return false;
        } else {
            return (checkBalance(n->l) && checkBalance(n->r));
        }
        return true;
    }

public:
    void Insert(int data) {
        Insert(root, data);
    }

    bool checkBalance() {
        return checkBalance(root);
    }
};

int main() {
    BST bst;
    int elem = 0;
    std::cin >> elem;
    while (elem != 0) {
        bst.Insert(elem);
        std::cin >> elem;
    }
    std::cout << (bst.checkBalance() ? "YES" : "NO") << std::endl;
}
