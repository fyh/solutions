# include <stdio.h>
# include <string.h>
const int maxn = 100005;
int N, M;
int ID;
int l[maxn], r[maxn];
int h[maxn], ne[maxn*2], va[maxn*2], E;
int a[maxn];
int sum[maxn];
void inh(int n)
{
    memset(h, -1, sizeof(h[0])*(n+1));
}
void in(int u, int v)
{
    va[++E] = v;
    int t = h[u];
    h[u] = E;
    ne[E] = t;
}
void dfs(int c, int f)
{
    l[c] = ++ID;
    for (int i = h[c]; i != -1; i = ne[i]) {
        int &t = va[i];
        if (t != f) {
            dfs(t, c);
        }
    }
    r[c] = ID;
}
int low_bit(int x) {return x&-x;}
void add(int i, int d)
{
    for (; i <= N; i+=low_bit(i)) {
        sum[i] += d;
    }
}
int get_sum0(int ri)
{
    int ret = 0;
    for (; ri > 0; ri-=low_bit(ri)) {
        ret += sum[ri];
    }
    return ret;
}
int get_sum(int le, int ri)
{
    return get_sum0(ri) - get_sum0(le-1);
}
void init(int n)
{
    memset(sum, 0, sizeof(sum[0])*(n+1));
    for (int i = 1; i <= n; ++i) add(i, 1);
}
# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;
    E = 0;
    scanf("%d", &N);
    inh(N);
    for (int i = 1; i < N; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        in(x, y);
        in(y, x);
    }
    ID = 0;
    dfs(1, 0);
    scanf("%d", &M);
    for (int i = 1; i <= N; ++i) a[i] = 1;
    init(N);
    for (int i = 0; i < M; ++i) {
        char ch[5];
        int x;
        scanf("%s%d", ch, &x);
        if (ch[0] == 'C') {
            int &t = a[ l[x] ];
            add(l[x], t==0 ? 1:-1);
            t = 1 - t;
        } else {
            printf("%d\n", get_sum(l[x], r[x]));
        }
    }

    return 0;
}
