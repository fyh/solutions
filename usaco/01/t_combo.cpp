/*
ID: yajunwf1
LANG: C++11
TASK: combo
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

int n;
int a[2][3];

int getd(int x, int y)  {
    int t = abs(y - x);
    return min(t, n-t);
}

bool ok(int x, int y, int z, int k) {
    return getd(x,a[k][0])<=2 && getd(y,a[k][1])<=2 && getd(z,a[k][2])<=2;
}

int main()
{
    rdio(combo);

    cin >> n;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (ok(i,j,k,0) || ok(i,j,k,1)) ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
