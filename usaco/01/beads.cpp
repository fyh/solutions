/*
ID: yajunwf1
LANG: C++11
TASK: beads
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

const int maxn = 350*2 + 5;

int n;
char s[maxn];
int r[maxn][2], l[maxn][2];

int main()
{
    rdio(beads);

    cin >> n >> s;
    for (int i = 0; i <= n; ++i) s[i+n] = s[i];

    // begin of ugly code
    for (int i = 0; s[i]; ++i) {
        if (!i) {
            if (s[i] == 'r') {
                l[i][0] = 1;
                l[i][1] = 0;
            } else if (s[i] == 'b') {
                l[i][1] = 1;
                l[i][0] = 0;
            } else {
                l[i][0] = 1;
                l[i][1] = 1;
            }
        } else {
            if (s[i] == 'r') {
                l[i][0] = l[i-1][0] + 1;
                l[i][1] = 0;
            } else if (s[i] == 'b') {
                l[i][0] = 0;
                l[i][1] = l[i-1][1] + 1;
            } else {
                l[i][0] = l[i-1][0] + 1;
                l[i][1] = l[i-1][1] + 1;
            }
        }
    }
    memset(r, 0, sizeof(r));
    for (int i = 2*n-1; i >= 0; --i) {
        if (s[i] == 'r') {
            r[i][0] = r[i+1][0] + 1;
            r[i][1] = 0;
        } else if (s[i] == 'b') {
            r[i][0] = 0;
            r[i][1] = r[i+1][1] + 1;
        } else {
            r[i][0] = r[i+1][0] + 1;
            r[i][1] = r[i+1][1] + 1;
        }
    }
    // end of ugly code

    int ans = 0;
    for (int i = 0; s[i]; ++i) {
        ans = max(ans, l[i][0] + r[i+1][0]);
        ans = max(ans, l[i][0] + r[i+1][1]);
        ans = max(ans, l[i][1] + r[i+1][1]);
        ans = max(ans, l[i][1] + r[i+1][0]);
    }

    cout << min(ans, n) << endl;

    return 0;
}
