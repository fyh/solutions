# include <iostream>
# include <vector>
# include <map>
# include <stdio.h>
# include <string.h>
# include <algorithm>
using namespace std;

# define testin freopen("in.txt", "r", stdin);

const int maxn = 105;
const int maxl = 105;

int n;
char s[maxn][maxl];
int y[maxn];
int r[maxn];
char tt[maxl];

bool cmp(const int &a, const int &b) {
    return y[a] >= y[b];
}

void solve() {
    gets(tt); sscanf(tt, "%d", &n);
    for (int i = 0; i < n; ++i) {
        gets(s[i]); //cout << s[i] << endl;
        int len = strlen(s[i]);
        for (int j = len-1; j >= 0; --j) {
            if (s[i][j] == ' ') {
                sscanf(s[i]+j, "%d", &y[i]);
                s[i][j] = 0;
                break;
            }
        }
        r[i] = i;
    }
    sort(r, r+n, cmp);
    for (int i = 0; i < n; ++i) {
        puts(s[r[i]]);
    }
}

int main()
{
    // testin;

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    gets(tt); sscanf(tt, "%d", &T);
    while (T--) {
        solve();
    }

    return 0;
}
