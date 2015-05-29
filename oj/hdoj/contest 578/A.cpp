# include <vector>
# include <queue>
# include <stdio.h>
# include <iostream>
# include <string.h>
const int maxn = 105;
int n, m;
int in[maxn];
std::vector<int> G[maxn];
int main()
{
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i <= n; ++i) in[i] = 0, G[i].clear();
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            G[y].push_back(x);
            ++in[x];
        }
        std::queue<int> Q;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) if (!in[i]) Q.push(i), ++cnt;
        while (Q.size()) {
            int t = Q.front(); Q.pop();
            for (int i = 0; i < G[t].size(); ++i) {
                int p = G[t][i];
                --in[p];
                if (!in[p]) Q.push(p), ++cnt;
            }
        }
        while (Q.size()) Q.pop();
        if (cnt == n) puts("YES");
        else puts("NO");
    }
    return 0;
}
