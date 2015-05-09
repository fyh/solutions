# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>

using namespace std;

# define testin freopen("in.txt", "r", stdin)


char s[105];
int k;
bool vis[26];
int cnt;
int pos[30];

int main()
{
    testin;
    scanf("%d%s", &k, s);
    memset(vis, false, sizeof(vis));
    vis[ s[0]-'a' ] = true;
    cnt = 0;
    pos[0] = 0;
    cnt = 1;
    for (int i = 0; s[i]; ++i) {
        int t = s[i] - 'a';
        if (!vis[t]) {
            pos[cnt++] = i;
            vis[t] = true;
        }
    }
    if (cnt < k) {
        printf("NO\n");
    } else {
        printf("YES\n");
        pos[k] = strlen(s);
        for (int i = 0; i < k; ++i) {
            for (int j = pos[i]; s[j] && j < pos[i+1]; ++j) {
                printf("%c", s[j]);
            }
            printf("\n");
        }
    }

    return 0;
}
