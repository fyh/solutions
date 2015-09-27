# include <iostream>
# include <cstdio>
# include <algorithm>

char s[55][1005];
char ans[1005];
int c[256];
int r[5];
int f[5];

bool cmp(const int x, const int y) {
    if (f[x]==f[y]) return x<y ? true:false;
    return f[x]>f[y] ? true:false;
}
int main()
{
    freopen("in.txt", "r", stdin);
    c['A'] = 0;
    c['C'] = 1;
    c['G'] = 2;
    c['T'] = 3;
    c[0] = 'A';
    c[1] = 'C';
    c[2] = 'G';
    c[3] = 'T';

    int T, m, n;
    std::cin >> T;
    while (T--) {
        int ans2 = 0;
        std::cin >> m >> n;
        for (int i = 0; i < m; ++i) std::cin >> s[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) r[j] = j, f[j] = 0;
            for (int j = 0; j < m; ++j) ++f[ c[s[j][i]] ];
            std::sort(r, r+4, cmp);
            // for (int j = 0; j < 5; ++j) std::cout << f[r[j]] << "\t"; std::cout << std::endl;
            ans[i] = c[ r[0] ];
            ans2 += m-f[r[0]];
        }
        ans[n] = 0;
        std::cout << ans << std::endl << ans2 << std::endl;
    }
    return 0;
}
