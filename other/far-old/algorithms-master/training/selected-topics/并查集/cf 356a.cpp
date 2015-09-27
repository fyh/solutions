# include <stdio.h>
using namespace std;

const int maxn = 300005;

int n, m;
int p[maxn];
int ans[maxn];

int find(int x) {
    return x==p[x] ? x:p[x]=find(p[x]);
}
void join(int l, int r, int x)
{
    while ((l=find(l)) <= r) {
        if(l != x) ans[l] = x, p[l] = l+1;
        ++l;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n+1; ++i) p[i] = ans[i] = i;
    for (int i = 1, x, l, r; i <= m; ++i) {
        scanf("%d%d%d", &l, &r, &x);
        join(l, r, x);
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1) putchar(' ');
        printf("%d", (ans[i]==i ? 0:ans[i]));
    }
    putchar('\n');

    return 0;
}
