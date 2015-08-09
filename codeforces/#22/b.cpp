# include <bits/stdc++.h>
using namespace std;

const int maxn = 30;

int n, m;
char b[maxn][maxn];

bool ok(int i, int j, int p, int q) {
    for (int r = i; r <= p; ++r) {
        for (int s = j; s <= q; ++s) {
            if (b[r][s] == '1') return false;
        }
    }
    return true;
}

int main()
{
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int p = i; p < n; ++p) {
                for (int q = j; q < m; ++q) {
                    if (ok(i,j,p,q)) {
                        ans = max(ans, 2*(p-i+1)+2*(q-j+1));
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
