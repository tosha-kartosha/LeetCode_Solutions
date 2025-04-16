/*Витя хочет придумать новую игру с числами. В этой игре от игроков требуется преобразовывать четырехзначные числа не содержащие нулей при помощи следующего разрешенного набора действий:

Можно увеличить первую цифру числа на 1, если она не равна 9;

Можно уменьшить последнюю цифру на 1, если она не равна 1;

Можно циклически сдвинуть все цифры на одну вправо;

Можно циклически сдвинуть все цифры на одну влево.

Например, применяя эти правила к числу 1234 можно получить числа 2234, 1233, 4123 и 2341 соответственно. Точные правила игры Витя пока не придумал, но пока его интересует вопрос, как получить из одного числа другое за минимальное количество операций.*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

const int INF = 1e9;


int bfs(std::string a, std::string b) {
    std::vector<int> dist(9000, INF);
    std::string c;
    std::queue<std::string> q;
    dist[std::atoi(a.c_str())-1000] = 0;
    q.push(a);
    while (!q.empty()) {
        std::string num = q.front();
        q.pop();
        if (num[0] != '9') {
            int number = num[0]-'0'+1;
            c = std::to_string(number) + num.substr(1, 3);
            if (dist[std::atoi(c.c_str())-1000] > dist[std::atoi(num.c_str())-1000] + 1) {
                dist[std::atoi(c.c_str())-1000] = dist[std::atoi(num.c_str())-1000] + 1;
                q.push(c);
            }
        }
        if (num[3] != '1') {
            int number = num[3]-'0'-1;
            c = num.substr(0, 3) + std::to_string(number);
            if (dist[std::atoi(c.c_str())-1000] > dist[std::atoi(num.c_str())-1000] + 1) {
                dist[std::atoi(c.c_str())-1000] = dist[std::atoi(num.c_str())-1000] + 1;
                q.push(c);
            }
        }
        c = num.substr(3, 1)+num.substr(0, 3);
        if (dist[std::atoi(c.c_str())-1000] > dist[std::atoi(num.c_str())-1000] + 1) {
            dist[std::atoi(c.c_str())-1000] = dist[std::atoi(num.c_str())-1000] + 1;
            q.push(c);
        }
        c = num.substr(1, 3)+num.substr(0, 1);
        if (dist[std::atoi(c.c_str())-1000] > dist[std::atoi(num.c_str())-1000] + 1) {
            dist[std::atoi(c.c_str())-1000] = dist[std::atoi(num.c_str())-1000] + 1;
            q.push(c);
        }
    }
    return dist[std::atoi(b.c_str())-1000];
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << bfs(a, b);
}
