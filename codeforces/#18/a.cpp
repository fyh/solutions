# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define testin freopen("in.txt", "r", stdin)

int x[3], y[3];

bool check(int i, int j, int k) {
    int dx1 = x[j] - x[i], dx2 = x[k] - x[i];
    int dy1 = y[j] - y[i], dy2 = y[k] - y[i];
    // if deg
    if (dx1*dy2 == dx2*dy1) return false;
    return dx1*dx2 + dy1*dy2 == 0;
}

bool checkRight() {
    return check(0, 1, 2) || check(1, 0, 2) || check(2, 0, 1);
}

int main()
{
    for (int i = 0; i < 3; ++i) cin >> x[i] >> y[i];

    if (checkRight()) puts("RIGHT");
    else {
        bool ok = false;
        for (int i = 0; i < 3; ++i) {
            ++x[i];
            if (checkRight()) {ok = true; break;}
            --x[i];

            --x[i];
            if (checkRight()) {ok = true; break;}
            ++x[i];

            ++y[i];
            if (checkRight()) {ok = true; break;}
            --y[i];

            --y[i];
            if (checkRight()) {ok = true; break;}
            ++y[i];
        }
        puts(ok ? "ALMOST":"NEITHER");
    }

    return 0;
}
