/*Дана строка s и число k . В строке s требуется найти подстроку максимальной длины, в которой все различные символы встречаются не менее k раз.
Идея: D&C*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSubstring(string s, int k) {
    int n = s.length();
    if (n == 0 || k > n) return 0;
    if (k <= 1) return n;
    
    unordered_map<char, int> count;
    for (char c : s) count[c]++;
    
    int left = 0;
    while (left < n && count[s[left]] >= k) left++;
    if (left >= n-1) return left;
    
    int ls1 = longestSubstring(s.substr(0, left), k);
    while (left < n && count[s[left]] < k) left++;
    int ls2 = (left < n) ? longestSubstring(s.substr(left), k) : 0;
    
    return max(ls1, ls2);
}

int main() {
    int s, k;
    cin >> s >> k;
    string seq;
    cin >> seq;
    cout << longestSubstring(seq, k) << endl;
    return 0;
}
