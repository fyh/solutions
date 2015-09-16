# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
# include <map>
# include <set>
# include <vector>
using namespace std;
typedef long long int lli;

# define testin freopen("in.txt", "r", stdin)

const int maxn = 50005;

char s[50005];
int st[4][maxn], top[4];

int getIdx(int ch) {
    if (ch == '9') return 0;
    if (ch == '7') return 1;
    if (ch == '0') return 2;
    if (ch == '6') return 3;
    return 4;
}

void solve() {
    for (int i = 0; i < 4; ++i) top[i] = 0;
    for (int i = 0; s[i]; ++i) {
        int t = getIdx(s[i]);
        if (t < 4) {
            st[t][ top[t]++ ] = i;
        }
    }

    int ans = 0;
    int i = 0, j = 0, k = 0, p = 0;
    for (i = 0; i < top[0]; ++i) {
        bool fi = false;
        for (; j < top[1]; ++j) {
            if (st[1][j] < st[0][i]) continue;
            if (st[1][j] > st[0][i]) {
                for (; k < top[2]; ++k) {
                    if (st[2][k] < st[1][j]) continue;
                    if (st[2][k] > st[1][j]) {
                        for (; p < top[3]; ++p) {
                            if (st[3][p] < st[2][k]) continue;
                            if (st[3][p] > st[2][k]) {
                                fi = true;
                                ++ans;
                                ++p;
                                break;
                            }
                        }
                        ++k;
                        break;
                    }
                }
                ++j;
                break;
            }
        }
        if (!fi) {
            printf("%d\n", ans);
            return ;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    //testin;

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        solve();
    }

    return 0;
}
