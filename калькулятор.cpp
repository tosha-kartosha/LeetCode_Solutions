/*Имеется калькулятор, который выполняет три операции:
Прибавить к числу X единицу.
Умножить число X на 2.
Умножить число X на 3.
Определите кратчайшую последовательность операций, необходимую для получения из числа 1 заданное число N.*/

#include <iostream>
#include <vector>

const int INF = 1e9;

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> sequence(n+1);
    if (n == 1) {
        std::cout << 1;
        return 0;
    }
    for (int i = 2; i <= n; ++i) {
        int min = INF;
        if (i % 2 == 0) {
            min = (min < sequence[i / 2] ? min : sequence[i / 2]);
        }
        if (i % 3 == 0) {
            min = (min < sequence[i / 3] ? min : sequence[i / 3]);
        }
        min = (min < sequence[i - 1] ? min : sequence[i - 1]);
        sequence[i] = min + 1;
    }
    std::cout << sequence[n];
    return 0;
}
