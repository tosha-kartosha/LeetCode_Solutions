/*Над двоичной записью числа N выполняются следующие операции:
1) Если число заканчивается на ноль, то этот ноль удаляется
2) Если число заканчивается на единицу, то из него вычитается единица
Определите, сколько операций потребуется чтобы превратить число N в ноль*/
#include <iostream>

void to_zero(int n, int & count) {
    if (n == 0) return;
    if (n % 2 == 0) {
        count ++;
        to_zero(n >> 1, count);
    }
    else {
        count ++;
        to_zero(n-1, count);
    }
}


int main() {
    int n = 0, count = 0;
    std::cin >> n;
    to_zero(n, count);
    std::cout << count << std::endl;
}
/*def to_zero(n, count):
    if (n == 0):
        return count
    if (n % 2 == 0):
        count += 1
        n = int(bin(n)[2:][:-1], 2)
        return to_zero(n, count)
    else:
        count += 1
        return to_zero(n-1, count)


n = int(input())
print(to_zero(n, 0))*/
