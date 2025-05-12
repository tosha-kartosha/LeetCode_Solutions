/*Билл пытается компактно представить последовательности прописных символов от A до Z с помощью упаковки повторяющихся подпоследовательностей внутри них. Например, один из способов представить последовательность AAAAAAAAAABABABCCD - это 10(A)2(BA)B2(C)D.
Он формально определяет сжатые последовательности символов и правила перевода их в несжатый вид следующим образом:
- Последовательность, содержащая один символ от A до Z, является упакованной. Распаковка этой последовательности даёт ту же последовательность из одного символа.
- Если S и Q - упакованные последовательности, то SQ - также упакованная последовательность. Если S распаковывается в S', а Q распаковывается в Q', то SQ распаковывается в S'Q'.
- Если S - упакованная последовательность, то X(S) - также упакованная последовательность, где X - десятичное представление целого числа, большего 1. Если S распаковывается в S', то X(S) распаковывается в S', повторённую X раз.
Следуя этим правилам, легко распаковать любую заданную упакованную последовательность. Однако Биллу более интересен обратный переход.
Он хочет упаковать заданную последовательность так, чтобы результирующая сжатая последовательность содержала наименьшее возможное число символов.
Ограничения: длина исходной последовательности от 1 до 100.*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

string compress(const string& s) {
    int n = s.size();
    vector<vector<string>> dp(n, vector<string>(n));
    
    for (int i = 0; i < n; ++i) {
        dp[i][i] = s[i];
    }
    
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            
            dp[i][j] = s.substr(i, len);
            
            for (int k = i; k < j; ++k) {
                string candidate = dp[i][k] + dp[k+1][j];
                if (candidate.size() < dp[i][j].size()) {
                    dp[i][j] = candidate;
                }
            }
            
            string pattern = s.substr(i, len);
            int pattern_len = len;
            for (int l = 1; l <= len/2; ++l) {
                if (len % l != 0) continue;
                bool is_repeat = true;
                for (int pos = l; pos < len; ++pos) {
                    if (pattern[pos] != pattern[pos % l]) {
                        is_repeat = false;
                        break;
                    }
                }
                if (is_repeat) {
                    pattern_len = l;
                    break;
                }
            }
            
            if (pattern_len < len) {
                int repeat = len / pattern_len;
                string compressed;
                if (repeat > 1) {
                    compressed = to_string(repeat) + "(" + dp[i][i+pattern_len-1] + ")";
                } else {
                    compressed = dp[i][i+pattern_len-1];
                }
                if (compressed.size() < dp[i][j].size()) {
                    dp[i][j] = compressed;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "(" << i << "," << j << "): " << dp[i][j] << std::endl;
        }
    }
    return dp[0][n-1];
}

int main() {
    string s;
    cin >> s;
    cout << compress(s) << endl;
    return 0;
}
