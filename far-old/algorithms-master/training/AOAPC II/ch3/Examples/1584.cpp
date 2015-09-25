# include <iostream>
# include <cstring>
char s[205];
int n;
bool gt(int x, int y) {
    for (int i = 0; i < n; ++i) {
        if (s[x+i] > s[y+i]) return true;
        else if (s[x+i] < s[y+i]) return false;
    }
    return false;
}
int main()
{
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> s;
        n = strlen(s);
        for (int i = 0; i < n; ++i) s[i+n] = s[i]; s[2*n] = 0;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (gt(ans, i)) ans = i;
        }
        s[ans+n] = 0;
        std::cout << s+ans << std::endl;
    }

    return 0;
}
