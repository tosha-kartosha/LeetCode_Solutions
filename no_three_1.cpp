// Определите количество последовательностей из нулей и единиц длины n, в которых никакие три единицы не стоят рядом.

#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    if (n == 1) {
        std::cout << 2;
        return 0;
    } else if (n == 2) {
        std::cout << 4;
        return 0;
    } else if (n == 3) {
        std::cout << 7;
        return 0;
    }
    long long int a = 2, b = 4, c = 7, ans = 0;
    for (int i = 4; i <= n; ++i) {
        ans = a + b + c;
        a = b;
        b = c;
        c = ans;
    }
    std::cout << ans;
    return 0;
}
