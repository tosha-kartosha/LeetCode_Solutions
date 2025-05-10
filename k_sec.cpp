//Идёт k-я секунда суток. Определите, сколько целых часов h и целых минут m прошло с начала суток
#include <iostream>

int main() {
    int n = 0, h = 0, m = 0;
    std::cin >> n;
    h = n / 3600;
    n -= (h*3600);
    m = n / 60;
    std::cout << "It is " << h << " hours " << m << " minutes." << std::endl;
    return 0;
}
