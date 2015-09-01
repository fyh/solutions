# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n, m;

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

void go(int sx, int sy, int tx, int ty, int d) {
    while (true) {
        cout << sx << ' ' << sy << endl;
        if (sx == tx && sy == ty) break;
        assert(1<=sx&&sx<=n&&1<=sy&&sy<=m);
        sx += dx[d], sy += dy[d];
    }
}

int main()
{
    // todo
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    if (n == 1 || m == 1) {
        cout << 1 << endl << n << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
        if (n == 1) go(1, 1, n, m, 3);
        else go(1, 1, n, m, 1);
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }

    if ((n*m)%2 == 0) {
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        if (n%2 == 0) {
            for (int i = 1; i <= n; ++i) {
                if (i%2 == 0) {
                    go(i, m, i, 2, 2);
                } else {
                    go(i, 2, i, m, 3);
                }
            }
            go(n, 1, 1, 1, 0);
        } else {
            for (int i = 1; i <= m; ++i) {
                if (i%2 == 0) {
                    go(n, i, 2, i, 0);
                } else {
                    go(2, i, n, i, 1);
                }
            }
            go(1, m, 1, 1, 2);
        }
    } else {
        cout << 1 << endl << n << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
        int d = 1;
        for (int i = 1; i <= n; ++i) {
            if (i%2 == 0) {
                go(i, m, i, 1, 2);
            } else {
                go(i, 1, i, m, 3);
            }
        }
        cout << 1 << ' ' << 1 << endl;
    }

    return 0;
}
