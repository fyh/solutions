# include <iostream>
# include <cstring>
# include <cstdio>

int r, c;
char b[15][15];
int num[15][15];

int main()
{
    int ica = 0;
    while (1) {
        std::cin >> r >> c;
        if (!r) break;
        for (int i = 1; i <= r; ++i) scanf("%s", b[i]+1);
        memset(num, 0, sizeof(num));
        int id = 1;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (b[i][j] == '*') continue;
                if (i==1 || j==1 || b[i-1][j]=='*' || b[i][j-1]=='*') {
                    num[i][j] = id++;
                }
            }
        }
        if (ica) std::cout << std::endl;
        std::cout << "puzzle #" << ++ica << ":" << std::endl;
        std::cout << "Across" << std::endl;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (num[i][j] && (j==1||b[i][j-1]=='*')) {
                    printf("%3d.", num[i][j]);
                    for (int k = j; k<=c && b[i][k] != '*'; ++k) std::cout << b[i][k];
                    std::cout << std::endl;
                }
            }
        }
        std::cout << "Down" << std::endl;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (num[i][j] && (i==1||b[i-1][j]=='*')) {
                    printf("%3d.", num[i][j]);
                    for (int k = i; k<=r && b[k][j]!='*'; ++k) std::cout << b[k][j];
                    std::cout << std::endl;
                }
            }
        }
    }

    return 0;
}
