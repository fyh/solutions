# include <bits/stdc++.h>

# define INF(type) ( std::numeric_limits<type>::max() )
# define get_bit(_x, _i) (((_x)>>(_i))&(0x1))
# define clr_bit(_x, _i) ((_x)&(~((0x1)<<(_i))))
# define flip_bit(_x, _i) ((_x)^((0x1)<<(_i)))

const int maxn = 24;

int n;
int gx, gy;
int x[maxn], y[maxn];
int ti[maxn];
int co[maxn][maxn];

void read(void) {
    scanf("%d%d%d", &gx, &gy, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
}

int sqr(int x) { return x * x; }

void pre(void) {
    for (int i = 0; i < n; ++i) {
        ti[i] = sqr(x[i]-gx) + sqr(y[i]-gy);
    }
    for (int i = 0; i < n; ++i) {
        for (int j =  0; j < n; ++j) {
            if (i == j) co[i][j] = 0;
            else {
              int a = ti[i], b = sqr(x[i]-x[j]) + sqr(y[i]-y[j]), c = ti[j];
              //  co[i][j] = std::min(a+b+c, 2*b + 2*std::min(a,c));
              co[i][j] = a + b + c;
            }
        }
    }
}


int f[1<<maxn];
int p[1<<maxn];

void init_dp(void) {
    memset(f, -1, sizeof(f));
    f[0] = 0;
}


/// TLE : n^2*2^n
int dp(int s) {
    if (~f[s]) return f[s];
    f[s] = INF(int);
    for (int i = 0; i < maxn; ++i) {
        if (get_bit(s,i)) {
            int t = clr_bit(s, i);
            int cur = dp(t) + 2*ti[i];
            if (cur < f[s]) {
                f[s] = cur;
                p[s] = t;
            }
            for (int j = i+1; j < maxn; ++j) if (get_bit(s,j)) {
                int u = clr_bit(t, j);
                int cur2 = dp(u) + co[i][j];
                if (cur2 < f[s]) {
                    f[s] = cur2;
                    p[s] = u;
                }
            }
            break;
        }
    }
    return f[s];
}

void print(int s) {
    if (!s) printf("0 ");
    else {
        int t = p[s];
        print(t);
        for (int i = 0; i < maxn; ++i) {
            if (get_bit(t,i) != get_bit(s, i)) printf("%d ", i+1);
        }
        printf("0 ");
    }
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    //testin;

    read();
    pre();

    init_dp();

 //   for (int i = 0; i < (1<<n); ++i) std::cout << dp(i) << std::endl;

    printf("%d\n", dp((1<<n)-1));
    print((1<<n)-1);

    return 0;
}
