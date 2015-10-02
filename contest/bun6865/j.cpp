# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1005;

bool mk[maxn][4];

int n;
lli x[maxn], y[maxn];

lli sx, sy;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

bool iso(int i, int di) {
    lli xx = x[i] - sx;
    lli yy = y[i] - sy;
    if (xx != 0) xx /= abs(xx);
    if (yy != 0) yy /= abs(yy);
    return (xx == dx[di] && yy == dy[di]);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        memset(mk, false, sizeof(mk));
        int di = 0;
        sx = 0, sy = 0;
        lli ans = 0;
        bool enc;
        bool lop = false;
        lli dist;
        while (true) {
            enc = false;
            dist = 2e9;
            dist *= 1e6;
            int ti;
            for (int i = 0; i < n; ++i) {
                if (iso(i, di)) {
                    enc = true;
                    lli cur = abs(sx-x[i]) + abs(sy-y[i]) - 1;
                    if (dist > cur) {
                        ti = i;
                        dist = cur;
                    }
                }
            }
            if (mk[ti][di]) lop = true;
            mk[ti][di] = true;
            if (lop || !enc) break;
            ++ans;
            sx += dx[di] * dist;
            sy += dy[di] * dist;
            di = (di+1)%4;
        }
        if (lop) cout << "-1" << endl;
        else cout << ans << endl;
    }

    return 0;
}
