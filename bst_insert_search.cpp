/* Напишите программу, которая будет реализовывать действия в бинарном дереве поиска «вставить» и «найти» (по значению). Программа должна обрабатывать запросы трёх видов:
ADD n — если указанного числа еще нет в дереве, вставлять его и выводить слово «DONE», если уже есть — оставлять дерево как было и выводить слово «ALREADY».
SEARCH — следует выводить слово «YES» (если значение найдено в дереве) или слово «NO» (если не найдено). Дерево при этом не меняется.
PRINTTREE — выводить все дерево, обязательно используя алгоритм, указанный в формате вывода результатов.
На запрос PRINTTREE надо выводить дерево, обязательно согласно такому алгоритму:
template<class T> void print_tree(Node<T> *p, int level) {
  if (p == NULL) {
    return;
  }

  print_tree(p->left, level + 1);
  for(int i=0; i < level; i++) {
    cout « ".";
  }
  cout « p->data « endl;
  print_tree(p->right, level + 1);
}
Изначальный вызов этой функции — print_tree(root, 0).*/

#include <iostream>

class BST {
    struct Node {
        int data;
        Node *l = nullptr, *r = nullptr;
        Node(int data): data(data) {};
    } *root = nullptr;

    bool Insert(Node *&n, int data) {
        if (!n) {
            n = new Node(data);
            return true;
        }
        if (n->data == data) return false;
        if (data < n->data) return Insert(n->l, data);
        else return Insert(n->r, data); 
    }

    bool Search(Node *n, int target) {
        if (!n) return false;
        if (n->data == target) return true;
        if (target < n->data) return Search(n->l, target);
        else return Search(n->r, target);
    }

    void print(Node *n, int level) {
        if (!n) return;
        print(n->l, level + 1);
        for (int i = 0; i < level; ++i) {
            std::cout << ".";
        }
        std::cout<< n->data << std::endl;
        print(n->r, level + 1);
    }

public:
    bool Insert(int data) {
        return Insert(root, data);
    }

    bool Search(int target) {
        return Search(root, target);
    }

    void print() {
        print(root, 0);
    }
};

int main() {
    std::string command;
    BST bst;
    while (std::cin >> command) {
        if (command == "ADD") {
            int elem = 0;
            std::cin >> elem;
            std::cout << (bst.Insert(elem) ? "DONE" : "ALREADY") << std::endl;
        } else if (command == "SEARCH") {
            int elem = 0;
            std::cin >> elem;
            std::cout << (bst.Search(elem) ? "YES" : "NO") << std::endl;
        } else {
            bst.print();
        }
    }
}
