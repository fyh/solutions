# include <bits/stdc++.h>

# define testin freopen("data.in", "r", stdin)


# include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;
const int INF = 1005;

int n;
int x[maxn], y[maxn];

void read(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
}

int r[maxn];
int dx[maxn], dy[maxn];

class frac{
public:
    int x, y;
    frac() : x(0), y(0){}
    frac(int _x, int _y) : x(_x), y(_y) {}
    static bool cmp(const frac &a, const frac &b) {
        return a.y * b.x <= a.x * b.y;
    }
    static bool cless(const frac &a, const frac &b) {
        return a.y * b.x < a.x * b.y;
    }
};

frac ff[maxn];

int sg(int x) {
    return x > 0 ? 1 : -1;
}

# define testin freopen("data.in", "r", stdin)

int main()
{
    testin;

    long long int ans = 0;

    read();

    if (n < 3) {
        puts("0");
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        int k = 0;
        for (int j = 0; j < n; ++j) if (j!=i) {
            dx[k] = x[j]-x[i];
            dy[k] = y[j]-y[i];
            if (!dy[k]) dx[k] = 1;
            if (!dx[k]) dx[k] = 1, dy[k] = INF;
            if (dx[k] < 0) dx[k] = -dx[k], dy[k] = -dy[k];
            ff[k] = frac(dx[k], dy[k]);
            ++k;
        }
        sort(ff, ff + n - 1, frac::cless);
        for (int j = 0; j+1 < n; ++j) {
            int c = upper_bound(ff, ff+n-1, ff[j], frac::cless) - lower_bound(ff, ff+n-1, ff[j], frac::cless);
            ans += n - 1 - c;
        }
    }

    if (ans % 6 != 0) while (true);

    cout << ans / 6 << endl;

    return 0;
}
