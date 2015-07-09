# include <stdio.h>
# include <algorithm>

int n;
int g[55][55];

int main()
{
    // freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int ica = 0; ica < t; ++ica)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &g[i][j]);
                if (g[i][j] == 0) g[i][j] = 55;
            }
        }
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (g[x-1][y-1]>=55) puts("Sorry");
            else printf("%d\n", g[x-1][y-1]-1);
        }
    }
    return 0;
}
