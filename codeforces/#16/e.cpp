# include <bits/stdc++.h>

const int maxn = 20;
int n;
double f[1<<maxn];
double p[maxn][maxn];

int get(int S) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if ((S>>i)&0x1) ++ret;
    }
    return ret;
}

double dp(int S) {
    if (f[S] >= 0) return f[S];
    f[S] = 0.0;
    int bt = get(S) + 1;
    for (int i = 0; i < n; ++i) {
        if(!((S>>i) & 0x1)) {
            int t = S | (0x1<<i);
            double sum = 0;
            for (int j = 0; j < n; ++j) {
                if ((S>>j)&0x1) sum += 2.0/bt/(bt-1)*p[j][i];
            }
            f[S] += dp(t) * sum;
        }
    }
    return f[S];
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
   // testin;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf", &p[i][j]);
        }
    }
    for (int i = 0; i < (1<<n); ++i) f[i] = -1.0;
    f[(1<<n)-1] = 1;
    for (int i = 0; i < n; ++i) {
        printf("%.6lf ", dp(0x1<<i));
    }
    printf("\n");
    return 0;
}
