#include <iostream>
int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    
    std::string ans = s;
    
    for (int i = 1; i < n; ++i) {
        std::string current = s.substr(i);
        if (current < ans) {
            ans = current;
        }
    }
    
    std::cout << ans << std::endl;
    return 0;
}
