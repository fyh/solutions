// WA

# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

char s[maxn];
char t[maxn];
int n;
int w[256][256];
int p[256][256];

int main()
{
    cin >> s >> t >> n;

    memset(w, 0x3f, sizeof(w));
    for (int i = 0; i < n; ++i) {
        char a[5], b[5]; int W;
        cin >> a >> b >> W;
        w[ a[0] ][ b[0] ] = min(W, w[ a[0] ][ b[0] ]);
        p[a[0]][b[0]] = b[0];
    }
    if (strlen(s) != strlen(t)) {
        puts("-1");
        return 0;
    }
    for (int k = 'a'; k <= 'z'; ++k) {
        for (int i = 'a'; i <= 'z'; ++i) {
            for (int j = 'a'; j <= 'z'; ++j) {
                if (w[i][j] > w[i][k]+w[k][j]) {
                    w[i][j] = w[i][k]+w[k][j];
                    p[i][j] = j;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] != t[i]) {
            int x = s[i], y = t[i];
            int tmp = 0x3f3f3f3f;
            int des = y;
            for (int k = 'a'; k <= 'z'; ++k) {
                if (tmp > w[x][k]+w[y][k]) {
                    tmp = w[x][k]+w[y][k];
                    des = k;
                }
            }
            int cur = min(w[x][y], w[y][x]);
            if (tmp < cur) {
                s[i] = des;
            } else {
                if (w[x][y] < w[y][x]) {
                    s[i] = y;
                }
            }
            tmp = min(tmp, cur);
            if (tmp >= 0x3f3f3f3f) {
                puts("-1");
                return 0;
            }
            ans += tmp;
        }
    }
    cout << ans << endl << s << endl;

    return 0;
}
