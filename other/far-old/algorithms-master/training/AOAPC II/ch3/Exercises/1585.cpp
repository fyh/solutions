# include <iostream>
char s[105];
// OOXXOXXOOO
int main()
{
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> s;
        int cur = 0, ans = 0;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == 'O') {
                ++cur;
                ans += cur;
            } else {
                cur = 0;
            }
        }
        std::cout <<ans << std::endl;
    }
    return 0;
}
