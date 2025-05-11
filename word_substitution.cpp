/*С целью экономии чернил в картридже принтера было принято решение укоротить некоторые слова в тексте. Для этого был составлен словарь слов, до которых можно сокращать более длинные слова.
Слово из текста можно сократить, если в словаре найдется слово, являющееся началом слова из текста.
Например, если в списке есть слово "лом", то слова из текста "ломбард", "ломоносов" и другие слова, начинающиеся на "лом", можно сократить до "лом".
Если слово из текста можно сократить до нескольких слов из словаря, то следует сокращать его до самого короткого слова.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> diction;
    std::vector<std::string> words;
    std::string a, b;
    int max = 0;
    while (std::cin >> a) {
        diction.insert(a);
        max = (max < a.length() ? a.length() : max);
        if (std::cin.peek() == '\n') break;
    }
    while (std::cin >> b) {
        words.push_back(b);
        if (std::cin.peek() == '\n' || std::cin.peek() == EOF) break;

    }
    for (int i = 0; i < words.size(); ++i) {
        std::string elem = words[i];
        for (int j = 0; j <= max; ++j) {
            std::string str = elem.substr(0, j);
            if (diction.find(str) != diction.end()) {
                words[i] = str;
                break;
            }
        }
    }
    for (std::string ans : words) {
        std::cout << ans << " ";
    }
    return 0;
}
