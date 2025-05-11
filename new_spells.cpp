/*Гарри в печали: вот уже девять лет как он не достает свою волшебную палочку на камеру.
Но случилось чудо! Продюсеры дали добро на съемку новой части поттерианы, в этот раз в сеттинге дикого запада.
Режиссер поручил (уже не юному) волшебнику подготовить список благозвучных заклинаний, которых еще не было во вселенной.
Благозвучность заклинания определяется двумя факторами:
Во-первых, заклинание должно быть удобно произносить, поэтому в нем нужно иметь как можно больше гласных (буквы a, e, i, o, u).
Во-вторых, любое заклинание нужно произносить быстро, поэтому чем оно короче, тем лучше.
Гарри выписал в список потенциальные заклинания и теперь просит вас составить из них топ по благозвучности: отсортировать сначала по уменьшению количества гласных, а при одинаковым количестве гласных упорядочить по увеличению длины.
В случае, когда два заклинания имеют одинаковую благозвучность, из взаимный порядок должен быть такой же, какой в списке Гарри. Другими словами, ваша сортировка должна быть стабильной.*/

#include <iostream>
#include <vector>
#include <algorithm>

int count(std::string a) {
    int ans = 0;
    for (char elem : a) {
        if (elem == 'a' || elem == 'e' || elem == 'i' || elem == 'o' || elem == 'u') {
            ans++;
        }
    }
    return ans;
}
bool cmpr(std::pair<std::string, int> &a, std::pair<std::string, int> &b) {
    if (count(a.first) == count(b.first)) {
        if (a.first.length() == b.first.length()) {
            return a.second < b.second;
        }
        return (a.first.length() < b.first.length());
    }
    return (count(a.first) > count(b.first));
}


int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::pair<std::string, int>> spells(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> spells[i].first;
        spells[i].second = i;
    }
    std::sort(spells.begin(), spells.end(), cmpr);
    for (std::pair<std::string, int> charm: spells) {
        std::cout << charm.first << std::endl;
    }
}
