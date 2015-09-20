# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <map>
# include <set>
using namespace std;

# define testin freopen("in.txt", "r", stdin)

char s[15];
char t[15];

bool isPalin(char *str) {
    int n = strlen(str);
    int half = n / 2;
    for (int i = 0; i < half; ++i) {
        if (str[i] != str[n-1-i]) return false;
    }
    return true;
}

int main()
{
    bool ok = false;
    scanf("%s", s);
    int n = strlen(s);
    if (!n) ok = true;
    for (int i = 'a'; !ok && i <= 'z'; ++i) {
        for (int j = 0; j <= n; ++j) {
            t[n+1] = 0;
            int p = 0;
            for (int k = 0; k <= n; ++k) {
                if (k == j) t[k] = (char)i;
                else t[k] = s[p++];
            }
        // cout << (char)i << '\t' << t << endl;
            if (isPalin(t)) {
                ok = true;
                break;
            }
        }
    }

    if (ok) puts("Yes");
    else puts("No");

    return 0;
}

