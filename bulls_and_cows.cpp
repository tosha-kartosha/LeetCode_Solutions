/*Вася и Петя играют в игру «Быки и коровы».
Вася загадал число состоящее из N  цифр, а Петя пытается его отгадать. Петя называет число из N цифр, а Вася отвечает, сколько в нем «быков» и «коров».
Количество «быков» вычисляется как количество цифр, стоящих на своем месте.
Количество «коров» вычисляется как количество цифр, которые есть и загаданном Васей числе и в названном Петей, но стоят на разных местах. То есть эти цифры могут быть переставлены таким образом, чтобы стать «Быками».
По загаданному Васей и названному Петей числам определите количество «быков» и «коров». */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string n, n1;
    std::cin >> n >> n1;
    int bull = 0, cow = 0;
    std::vector<int> table(10, 0);
    std::vector<bool> s(n.length(), true);
    for (int i = 0; i < 10; ++i) {
        table[i] = std::count(n.begin(), n.end(), '0' + i);
    }
    for (int i = 0; i < n.length(); ++i) {
        if (n[i] == n1[i]) {
            bull ++;
            table[n[i] - '0'] --;
            s[i] = false;
        } else {
            for (int j = 0; j < n.length(); ++j) {
                if (i != j && n[j] == n1[i] && n[j] != n1[j] && s[j] && table[n[j] - '0'] > 0) {
                    cow += 1;
                    table[n[j] - '0']--;
                    s[j] = false;
                    break;
                }
            }
        }
    }
    std::cout << bull << std::endl;
    std::cout << cow << std::endl;
}

/*n = input()
n1 = input()
bik = 0
cow = 0
table = [0 for i in range(10)]
s = ['0'for i in range(len(n))]
for i in range(10):
    table[i] = str(n).count(str(i))

for i in range(len(n)):
    if (n[i] == n1[i]):
        bik += 1
        table[int(n[i])] -= 1
        s[i] = '1'
    else:
        for j in range(len(n)):
            if (i != j and n[j] == n1[i] and n[j] != n1[j] and s[j] != '1' and table[int(n[j])] > 0):
                cow += 1
                table[int(n[j])] -= 1
                s[j] = '1'
                break
print(bik)
print(cow)*/
