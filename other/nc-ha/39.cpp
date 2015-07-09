# include <algorithm>
# include <iostream>
# include <stdio.h>

int a[10];
bool vis[20][3];

int ans[105];
int cnt = 0;

void dfs(int c) {
    if (c == 8) {
        int cur = 0;
        for (int i = 0; i < 8; ++i) cur = cur*10 + a[i]+1;
        ans[cnt++] = cur;
        return ;
    }
    for (int i = 0; i < 8; ++i) {
        if (!vis[c+1+i+1][0] && !vis[c-i+8][1] && !vis[i+1][2]) {
            vis[c+1+i+1][0] = vis[c-i+8][1] = vis[i+1][2] = true;
            a[c] = i;
            dfs(c+1);
            vis[c+1+i+1][0] = vis[c-i+8][1] = vis[i+1][2] = false;
        }
    }
}

int main()
{
    dfs(0);

    std::sort(ans, ans+cnt);

    int n;
    while (~scanf("%d", &n)) {
        std::cout << ans[n-1] << std::endl;
    }

    return 0;
}
