//Задано две строки, нужно проверить, является ли одна анаграммой другой. Анаграммой называется строка, полученная из другой перестановкой букв.

#include <iostream>
#include <algorithm>
int main() {
    std::string first, second;
    std::cin >> first >> second;
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());
    std::cout << (first == second ? "YES" : "NO") << std::endl;
    return 0;
}
