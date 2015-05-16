# include <string.h>
# include <stdio.h>
# include <iostream>
# include <algorithm>
const int maxn = 100005;
int N;
int S[maxn], E[maxn];
int id[maxn];
int sum[maxn];
int ans[maxn];
int n;
bool cmp(const int x, const int y)
{
    if (S[x] != S[y]) return S[x] <= S[y];
    return E[x] >= E[y];
}
int low_bit(int x) {return x&-x;}
void add(int i, int d)
{
    for (; i <= n; i+=low_bit(i)) sum[i] += d;
}
int get_sum0(int r)
{
    int ret = 0;
    for (; r > 0; r-=low_bit(r)) ret += sum[r];
    return ret;
}
int get_sum(int l, int r)
{
    if (r < l) return 0;
    return get_sum0(r) - get_sum0(l-1);
}
void init(void)
{
    while (true) {
        scanf("%d", &N);
        if(!N) break;
        n = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &S[i], &E[i]);
            n = std::max(n, ++E[i]);
        }
        n = std::min(n, maxn-1);
        memset(sum, 0, sizeof(sum[0])*(n+1));
        for (int i = 0; i < N; ++i) id[i] = i;
        std::sort(id, id+N, cmp);
        for (int i = 0; i < N; ++i) {
            int j = id[i];
            if (i>0 && S[j]==S[id[i-1]] && E[j]==E[id[i-1]]) ans[j] = ans[id[i-1]];
            else ans[j] = get_sum(E[j], n);
            add(E[j], 1);
        }
        for (int i = 0; i < N; ++i) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}
# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;
    init();
    return 0;
}
