# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <map>
using namespace std;
typedef long long int lli;

const int maxn = 15;

lli fact[maxn];

void solve(char *str) {
    int ans = 0;
    int n = strlen(str);
    for (int i = 0; i < n; ++i) {
        int cl = 0;
        for (int j = i+1; j < n; ++j) {
            if (str[j] < str[i]) {
                ++cl;
            }
        }
        ans += cl * fact[n-1-i];
    }
    cout << ans+1 << endl;
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i < maxn; ++i) fact[i] = fact[i-1] * i;

    int n;
    char s[maxn];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        solve(s);
    }

    return 0;
}
