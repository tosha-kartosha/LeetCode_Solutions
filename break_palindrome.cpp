/*Палиндромом называется строка, которая читается одинаково слева-направо и справа-налево.
В заданной строке-палиндроме необходимо заменить один символ, чтобы она перестала быть палиндромом. При этом полученная строка должна быть лексикографически минимальной.
Строка A лексикографически меньше строки B (той же длины), если на первой различающейся позиции в строке A стоит меньший символ, чем в B.*/

#include <iostream>
int count(std::string s, char elem) {
    int ans = 0;
    for (char sym: s) {
        if (sym == elem) ans++;
    }
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;
    if (s.length() == 1) {
        std::cout << std::endl;
        return 0;
    }
    if (count(s, 'a') == s.length()) {
        std::cout << s.substr(0, s.length() - 1) << 'b';
        return 0;
    }
    else if (count(s, 'a') == s.length() - 1) {
        for (int j = s.length() - 1; j >= 0; j--) {
            if (s[j] == 'a') {
                std::cout << s.substr(0, j) << 'b' << s.substr(j+1);
                return 0;
            }
        }
    }
    else {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != 'a') {
                std::cout << s.substr(0, i) << 'a' << s.substr(i+1);
                return 0;
            }
        }
    }
    return 0;
}

/*s = input()
if len(s) == 1:
    print()
else:
    if (s.count('a') == len(s)):
        print(s[:-1]+'b')
    elif (s.count('a') == len(s)-1):
        for j in range(len(s)-1, -1, -1):
            if (s[j] == 'a'):
                print(s[:j]+'b'+s[j+1:])
                break
    else:    
        for i in range(len(s)):
            if s[i] != 'a':
                print(s[:i]+'a'+s[i+1:])
                break*/
