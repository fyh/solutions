# include <stdio.h>
# include <map>
# include <iostream>
using namespace std;

const int maxn = 1005;
int a[maxn][maxn];
int c2[maxn][maxn];
int c5[maxn][maxn];
char s[maxn][maxn];

map<int, int> m2;
map<int, int> m5;

int G2(int x) {
    if (x>0 && x%2 == 0 && !m2[x]) {
        int t = 0;
        while (x>0 && x%2 == 0) x/=2, ++t;
        m2[x] = t;
    }
    return m2[x];
}
int G5(int x) {
    if (x>0 && x%5 == 0 && !m5[x]) {
        int t = 0;
        while (x>0 && x%5 == 0) x/=5, ++t;
        m5[x] = t;
    }
    return m5[x];
}
void dp(int i, int j) {

    if (i < 0 || j < 0) return ;

    if (c2[i][j] != -1 && c5[i][j] != -1) return ;

    int t = a[i][j];
    c2[i][j] = G2(t);
    c5[i][j] = G5(t);

    dp(i, j-1);
    dp(i-1, j);

    if (i == 0) {
        c2[i][j] += c2[i][j-1];
        c5[i][j] += c5[i][j-1];
        s[i][j] = 'R';
    } else if (j == 0) {
        c2[i][j] += c2[i-1][j];
        c5[i][j] += c5[i-1][j];
        s[i][j] = 'D';
    } else if ( std::min(G2(t)+c2[i-1][j], G5(t)+c5[i-1][j]) <
         std::min(G2(t)+c2[i][j-1], G5(t)+c5[i][j-1])
        ) {
        c2[i][j] += c2[i-1][j];
        c5[i][j] += c5[i-1][j];
        s[i][j] = 'D';
    } else {
        c2[i][j] += c2[i][j-1];
        c5[i][j] += c5[i][j-1];
        s[i][j] = 'R';
    }
}

void pr(int x, int y)
{
    if (x < 0 || y < 0) return ;
    if (!x && !y) return ;
    if (s[x][y] == 'D') pr(x-1, y);
    else pr(x, y-1);
    printf("%c", s[x][y]);
}

int n;
# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            c2[i][j] = c5[i][j] = -1;
            s[i][j] = 0;
        }
    }
    dp(n-1,n-1);
    printf("%d\n", std::min(c2[n-1][n-1], c5[n-1][n-1]));
    pr(n-1,n-1);
    printf("\n");

    return 0;
}
