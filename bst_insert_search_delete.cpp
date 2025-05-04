/*Напишите программу, которая будет реализовывать действия в бинарном дереве поиска «вставить», «удалить» и «найти» (по значению). Программа должна обрабатывать запросы четырёх видов:
ADD n — если указанного числа еще нет в дереве, вставлять его и выводить слово «DONE», если уже есть — оставлять дерево как было и выводить слово «ALREADY».
DELETE n — если указанное число есть в дереве, удалять его и выводить слово «DONE», если нет — оставлять дерево как было и выводить слово «CANNOT». При удалении элемента, имеющего два сына, обязательно обменивать значение с максимальным элементом левого поддерева.
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

    int max(Node *n) {
        if (!n) return -1;
        while (n->r) {
            n = n->r;
        }
        return n->data;
    }

    bool Insert(Node *&n, int data) {
        if (!n) {
            n = new Node(data);
            return true;
        }
        if (n->data == data) return false;
        if (data < n->data) return Insert(n->l, data);
        else return Insert(n->r, data);
    }

    bool Delete(Node *&n, int data) {
        if (!n) return false;
        if (data == n->data) {
            if (!(n->l) && !(n->r)) {
                n = nullptr;
            } else if (n->l && !(n->r)) {
                n = n->l;
            } else if (!(n->l) && n->r) {
                n = n->r;
            } else {
                int elem = max(n->l);
                Delete(n->l, elem);
                n->data = elem;
            }
            return true;
        } else if (data < n->data) return Delete(n->l, data);
        else return Delete(n->r, data);
    }

    bool Search(Node *n, int target) {
        if (!n) return false;
        if (n->data == target) return true;
        if (target < n-> data) return Search(n->l, target);
        else return Search(n->r, target);
    }

    void print(Node *n, int level) {
        if (!n) return;
        print(n->l, level + 1);
        for (int i = 0; i < level; ++i) {
            std::cout << ".";
        }
        std::cout << n->data << std::endl;
        print(n->r, level + 1);
    }


public:
    int max() {
        return max(root);
    }

    bool Insert(int data) {
        return Insert(root, data);
    }

    bool Delete(int data) {
        return Delete(root, data);
    }
    
    bool Search(int target) {
        return Search(root, target);
    }

    void print() {
        print(root, 0);
    }

};

int main() {
    BST bst;
    std::string command;
    while (std::cin >> command) {
        if (command == "ADD") {
            int key = 0;
            std::cin >> key;
            std::cout << (bst.Insert(key) ? "DONE" : "ALREADY") << std::endl;
        } else if (command == "PRINTTREE") {
            bst.print();
        } else if (command == "SEARCH") {
            int key = 0;
            std::cin >> key;
            std::cout << (bst.Search(key) ? "YES" : "NO") << std::endl;
        } else if (command == "DELETE") {
            int key = 0;
            std::cin >> key;
            std::cout << (bst.Delete(key) ? "DONE" : "CANNOT") << std::endl;
        }
    }
}
