/*Вам задан массив натуральных чисел nums размера n. До тех пор пока массив не пустой, вы можете совершать следующую операцию:
1. Выбрать натуральное число i ( 1 ≤ i ≤ n )
2. Добавить в свой кошелек n u m s i бурлей
3. Удалить nums_i, удалить все числа, равные nums (i + 1) и удалить все числа, равные nums (i - 1).
Если нет ни одного nums i + 1 и ни одного nums i - 1, то удаляется толькоnums i.
Какое максимальное количество бурлей вы сможете заработать?


Идея: ДП
- когда есть дубликаты, то при взятии хотя бы одного из них - можем брать все.
1. Вначале посчитает суммы для каждого элемента (сумма 0, сумма 1, сумма 2...)
2. начиная с sum[2] будет находить max между sum[i-1] или sum[i-2]+sum[i]*/

#include <iostream>
#include <vector>

int maxi(int a, int b) {
    if (a < b) return b;
    return a;
}

int main() {
    int n = 0;
    int max = 0;
    std::cin >> n;
    std::vector<int> numb(n);
    for (int i = 0; i < n; ++i) {
        int a = 0;
        std::cin >> a;
        numb[i] = a;
        max = (max < a ? a : max);
    }
    std::vector<int> sum(max+1, 0);
    for (int elem : numb) {
        sum[elem] += elem;
    }
    for (int i = 2; i <= max; ++i) {
        sum[i] = maxi(sum[i-1], sum[i-2]+sum[i]);
    }
    std::cout << sum[max] << std::endl;
}
