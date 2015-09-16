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

const int maxn = 4e4+5;

int n;
int x0[maxn], x1[maxn], y0[maxn], y1[maxn];
int r[maxn];

bool chk(int x, int y, int b) {
    return x0[b]<=x&&x<=x1[b]&&y0[b]>=y&&y1[b]<=y;
}

bool isIn(int a, int t, int b) {
    switch(t) {
        case 0: {
            return chk(x0[a], y0[a], b);
            break;
        }
        case 1: {
            return chk(x1[a], y0[a], b);
            break;
        }
        case 2: {
            return chk(x1[a], y1[a], b);
            break;
        }
        case 3: {
            return chk(x0[a], y1[a], b);
            break;
        }
    }
}

bool jd(int i, int j) {
    int a = r[i], b = r[j];
    for (int k = 0; k < 4; ++k) {
        if (isIn(a, k, b) || isIn(b, k, a)) return false;
    }
    return true;
}

int main()
{
    // testin;

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &x0[i], &y0[i], &x1[i], &y1[i]);
            r[i] = i;
        }
        if (n > 5000) printf("0\n");
        // sort(r, r+n, cmp);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (!jd(i,j)) ++ans;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

