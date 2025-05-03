// Для бинарного дерева поиска, построенного на заданных элементах, выведите список всех вершин, имеющих по два ребёнка, в порядке возрастания.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BST {
    struct Node {
        int key;
        Node *l = nullptr, *r = nullptr;
        Node(int key) : key(key) {}
    } *root = nullptr;
    
    void insert(Node *&n, int key) {
        if (!n) {
            n = new Node(key);
            return;
        }
        if (key == n->key) return;
        if (key < n->key) insert(n->l, key);
        else insert(n->r, key);
    }

    void print(Node *n) const {
        if (!n) return;
        print(n->l);
        if (n->l && n->r) std::cout << n->key << std::endl;
        print(n->r);
    }

public:
    void insert(int key) {
        insert(root, key);
    }
    
    void print() const {
        print(root);
    }
};


int main() 
{
	BST bst;
    while (true) {
        int x = 0;
        std::cin >> x;
        
        if (x == 0) {
            break;
        }
        bst.insert(x);
    }
    
    bst.print();
	return 0;
}
