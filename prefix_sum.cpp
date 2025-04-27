/*вывести суммы всех чисел в промежутках от a до b*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n = 0, t = 0;
    std::cin >> n >> t;
    std::vector<long long int> drinks(n+1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> drinks[i];
    }
    for (int i = 2; i <= n; ++i) {
        drinks[i] += drinks[i-1];
    }
    for (int i = 0; i < t; ++i) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        std::cout << drinks[b] - drinks[a - 1] << std::endl;
    }
    return 0;
}
