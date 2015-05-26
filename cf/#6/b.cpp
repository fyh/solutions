# include <set>
# include <stdio.h>
const int maxn = 105;
char b[maxn][maxn];
std::set<char> S;
int n, m;
char ch[5];
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d%d%s", &n, &m, ch);
    for (int i = 0; i < n; ++i) scanf("%s", b[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i][j] == ch[0]) {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (0<=ni&&ni<n && 0<=nj&&nj<m && b[ni][nj]!=ch[0] && b[ni][nj]!='.') {
                        S.insert(b[ni][nj]);
                    }
                }
            }
        }
    }
    printf("%u\n", S.size());
    return 0;
}

