# include <cstdio>
const int maxn = 50005;
int n, k;
int p[maxn];
int g[maxn];
int find(int x) {
    if (x == p[x]) return x;
    int t = find(p[x]);
    g[x] = ((g[p[x]] + g[x]) % 3 + 3) % 3;
    p[x] = t;
    return t;
}
# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;
    //while (scanf("%d%d", &n, &k) != EOF) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) p[i] = i, g[i] = 0;
        int ans = 0;
        for (int i = 0, od, x, y; i < k; ++i) {
            scanf("%d%d%d", &od, &x, &y);
            if (x>n||y>n || (od==2 && x==y)) {
                ++ans;
                continue;
            } else {
                int fx = find(x);
                int fy = find(y);
                if (fx != fy) {
                    p[fx] = fy;
                    g[fx] = ((g[y]-g[x]+od-1)%3+3)%3;
                } else if (((g[x]-g[y])%3+3)%3 != od-1){
                    ++ans;
                }
            }
        }
        printf("%d\n", ans);
    //}

    return 0;
}
