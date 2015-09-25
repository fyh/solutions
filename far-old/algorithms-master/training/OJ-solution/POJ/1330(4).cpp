# include <stdio.h>
# include <string.h>
# define N 10005
int n, fa[N];
char vis[N];
int main()
{
    int T, x, y, ica, i;
    scanf("%d", &T);
    for (ica = 0, x, y; ica < T; ++ica) {
        scanf("%d", &n);
        memset(fa+1, 0, sizeof(int)*n);
        memset(vis, 0, n+1);
        for (i = 1; i < n; ++i) {
            scanf("%d%d", &x, &y);
            fa[y] = x;
        }
        scanf("%d%d", &x, &y);
        while (vis[x]=7, x=fa[x]) ;
        while (!vis[y]) y = fa[y];
        printf("%d\n", y);
    }
    return 0;
}
