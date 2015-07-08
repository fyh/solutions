# include <stdio.h>
# include <iostream>

typedef long long int lli;

int m, n;
lli f[25][25];

int dp(int i, int j) {
    if (i < 0) return 0;
    if (f[i][j]) return f[i][j];
    if (i==0 || j==1) return f[i][j]=1;
    return f[i][j] = dp(i,j-1) + dp(i-j,j);
}

int main()
{
    for (int i = 1; i < 25; ++i) {
        for (int j = 1; j < 25; ++j) {
            dp(i,j);
        }
    }
    while (~scanf("%d%d", &m, &n)) {
        std::cout << f[m][n] << std::endl;
    }

    return 0;
}
