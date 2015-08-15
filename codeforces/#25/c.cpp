// see it clearly that the shortest distance might be over 1000

# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 305;

int n;
int d[maxn][maxn];

int k;
int a, b, c;

lli sum;

void calc()
{
    sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            d[j][i] = d[i][j] = std::min(d[i][j], d[j][i]);
            sum += d[i][j];
        }
    }
}

int main()
{
    // freopen("in.data", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }
    calc();
    cin >> k;
    for (int i = 0; i < k; ++i) {
        if (i) cout << ' ';
        cin >> a >> b >> c; --a, --b;
        if (c > d[a][b]) cout << sum;
        else {
            d[a][b] = d[b][a] = c;
            for (int x = 0; x < n; ++x) {
                d[a][x] = std::min(d[a][x], d[a][b]+d[b][x]);
                d[b][x] = std::min(d[b][x], d[b][a]+d[a][x]);
            }
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                        d[x][y] = std::min(d[x][y], d[x][a]+d[a][b]+d[b][y]);
                }
            }
            calc();
            cout << sum;
        }
    }
    cout << endl;

    return 0;
}
