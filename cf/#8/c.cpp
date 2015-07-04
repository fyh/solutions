# include <bits/stdc++.h>

# define get_bit(x, i) (((x)>>(i))&0x1)

const int maxn = 25;
const int INF = std::numeric_limits<int>::max();

int n;
int gx, gy;
int x[maxn], y[maxn];

int ti[maxn];
int co[maxn][maxn];

int f[1<<maxn];
int p[1<<maxn];

int sqr(int x) { return x * x; }

void read(void) {
    scanf("%d%d%d", &gx, &gy, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        ti[i] = sqr(x[i]-gx) + sqr(y[i]-gy);
    }
}

void pre(void) {
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            co[j][i] = co[i][j] = ti[i]+ti[j]+sqr(x[i]-x[j])+sqr(y[i]-y[j]);
        }
    }
}

int dp(void) {
    int m = 1 << n;
    std::fill(f, f+m, INF);
    f[0] = 0;
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < maxn; ++j) if (get_bit(i,j)){
            int t = i ^ (0x1<<j);
            if (f[i] > f[t] + 2*ti[j]) {
                f[i] = f[t] + 2*ti[j];
                p[i] = t;
            }
            for (int k = j+1; k < maxn; ++k) if (get_bit(i,k)) {
                int u = t ^ (0x1<<k);
                if (f[i] > f[u] + co[j][k]) {
                    f[i] = f[u] + co[j][k];
                    p[i] = u;
                }
            }
            break;
        }
    }
    return f[m-1];
}

void print(int s) {
    if (!s) {
        printf("0 ");
    } else {
        print(p[s]);
        for (int i = 0; i < maxn; ++i) {
            if (get_bit(s,i) != get_bit(p[s], i)) {
                printf("%d ", i+1);
            }
        }
        printf("0 ");
    }
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    // testin;

    read();
    pre();
    printf("%d\n", dp());
    print((1<<n)-1);

    return 0;
}
