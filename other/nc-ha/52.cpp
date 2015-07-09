# include <stdio.h>
# include <string.h>
# include <algorithm>

const int maxm = 25;
const int maxv = 10005;

int m, V;
int c[maxm], v[maxm], r[maxm];

void doit() {
}

bool cmp(const int &x, const int &y) {
    return v[x]*c[y] > v[y]*c[x];
}

int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &m, &V)) {
        if (!m && !V) break;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &c[i], &v[i]);
            r[i] = i;
        }
        std::sort(r, r + m, cmp);
        double ans = 0;
        int i = 0;
        while (V > 0 && i < m) {
            int t = r[i];
            if (V >= c[t]) {
                V-=c[t];
                ans += v[t];
            } else {
                ans += (V*1.0*v[t]/c[t]);
                V = 0;
            }
            ++i;
        }
        printf("%.2lf\n", ans);
    }

    return 0;
}
