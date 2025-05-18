// сжать строку по правилу: если повторяется 1 раз не менять, иначе записать символ и количество идущих подряд одинаковых символов.
#include <iostream>
int main() {
    std::string s, ans;
    std::cin >> s;
    int tek_count = 0;
    char tek = s[0];
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == tek) {
            tek_count++;
        } else {
            if (tek_count == 1) ans+= tek;
            else ans += (tek+std::to_string(tek_count));
            tek_count = 1;
            tek = s[i];
        }
    }
    if (tek_count == 1) ans+= tek;
    else ans += (tek+std::to_string(tek_count));
    std::cout << ans;
}
