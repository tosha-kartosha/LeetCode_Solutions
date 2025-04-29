//Дано n золотых слитков массой m1, …, mn. Ими наполняют рюкзак, который выдерживает вес не более w. Какую наибольшую массу золота можно унести в таком рюкзаке?

#include <iostream>
#include <vector>

int main() {
    int n = 0, w = 0;
    std::cin >> n >> w;
    std::vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }
    std::vector<int> massa(w+1);
    massa[0] = 1;
    for(int i = 0; i < n; ++i) {
        std::vector<int> massa_tmp = massa;
        for(int j = 1; j <= w; ++j) {
            if (j - weights[i] >= 0 && massa[j-weights[i]] == 1) {
                massa_tmp[j] = 1;
            }
        }
        massa = massa_tmp;
    }
    for (int i = w; i >= 0; --i) {
        if (massa[i] == 1) {
            std::cout << i;
            return 0;
        }
    }
}
