# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 305;

int n, m, k;
char b[maxn][maxn];

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> b[i]+1;

    int cnt = 0;
    int us = min(m, n);
    for (int s = 1; s <= us; ++s) {
        for (int i = s+1; i+s <= n; ++i) {
            for (int j = s+1; j+s <= m; ++j) {
                if (b[i][j] != '*') continue;
                bool ok = true;
                for (int d = 0; d < 4; ++d) {
                    if (b[i+s*dx[d]][j+s*dy[d]] != '*') {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ++cnt;
                    if (cnt == k) {
                        cout << i << ' ' << j << endl;
                        for (int d = 0; d < 4; ++d) {
                            cout << i+s*dx[d] << ' ' << j+s*dy[d] << endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }
    puts("-1");

    return 0;
}
