/*ася постоянно интересуется новыми языками программирования. Недавно, например, он узнал про систему работы с памятью в языке Gava. Ему стало интересно написать свой аллокатор.
Память он решил представить в виде отрезка прямой длины N, разбитого на единичные отрезки с номерами от 1 до N.
При необходимости выделения памяти Вася будет объединять подряд идущие отрезки, еще не входящие ни в какие группы. Когда память можно будет освободить,
группа будет уничтожаться и все входящие в нее отрезки могут быть использованы вновь.Реализацию этой структуры данных он решил поручить вам.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int n = 0, k = 0, command = 0, a = 0, b = 0;
    std::cin >> n >> k;
    
    std::map<int , std::pair<int, int>> line;
    for (int i = 0; i < k; ++i) {
        std::cin >> command;
        if (command == 1) {
            std::cin >> a >> b;
            bool flag = true;
            for (const auto& [key, value] : line) {
                if (!(b < value.first || a > value.second)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                std::cout << "1" << std::endl;
                line[a] = {a, b};
            } else std::cout << "0" << std::endl;
        } else {
            std::cin >> a;
            bool flag = true;
            for (auto it = line.begin(); it != line.end(); ++it) {
                if (a >= it->second.first && a <= it->second.second) {
                    std::cout << it->second.first << " " << it->second.second << std::endl;
                    line.erase(it);
                    flag = false;
                    break;
                }
            }
            if (flag) std::cout << "0 0" << std::endl;
        }
    }
    return 0;
}
