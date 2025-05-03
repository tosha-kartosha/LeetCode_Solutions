// Для полученного дерева выведите список всех листьев (вершин, не имеющих потомков) в порядке возрастания.

#include <iostream>

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

    void print(Node *n) {
        if (!n) return;
        print(n->l);
        if (!(n->l) && !(n->r)) std::cout << n->data << std::endl;
        print(n->r);
    }

public:
    void Insert(int data) {
        Insert(root, data);
    }

    void print() {
        print(root);
    }

};

int main() {
    int elem = 0;
    BST bst;
    std::cin >> elem;
    while (elem != 0) {
        bst.Insert(elem);
        std::cin >> elem;
    }
    bst.print();
    return 0;
}
