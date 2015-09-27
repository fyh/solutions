# include <iostream>
# include <cstring>
# include <cctype>
# include <cstdio>
char board[7][7];
void Swap(int x0, int y0, int x1, int y1)
{
    int ch = board[x0][y0];
    board[x0][y0] = board[x1][y1];
    board[x1][y1] = ch;
}
int readCase()
{
    char ch;
    int cnt = 0;
    while ((ch=getchar()) != EOF) {
        if (isalpha(ch) || ch==' ') {
            int x = cnt / 5 + 1;
            int y = cnt % 5 + 1;
            board[x][y] = ch;
            ++cnt;
        }
        if (cnt >= 25) break;
    }
    if (cnt < 25) return 0;
    return 1;
}
int main()
{
    int ica = 0;
    while ( readCase() ) {
        bool no_final = false;
        int x, y;
        for (int i = 1; i <= 5; ++i) {
            for (int j = 1; j <= 5; ++j) {
                if (board[i][j] == ' ') {
                    x = i, y = j;
                }
            }
        }
        int ch;
        while ((ch=getchar()) != '0') {
            if (no_final) continue;
            switch(ch) {
                case 'A': {
                    if (x-1 < 1) {no_final = true;}
                    else {Swap(x-1,y, x, y); --x;}
                    break;
                }
                case 'B': {
                    if (x+1 > 5) {no_final = true;}
                    else {Swap(x, y, x+1, y); ++x;}
                    break;
                }
                case 'L': {
                    if (y-1 < 1) {no_final = true;}
                    else {Swap(x,y, x, y-1); --y;}
                    break;
                }
                case 'R' : {
                    if (y+1 > 5) {no_final = true;}
                    else {Swap(x,y, x, y+1); ++y;}
                    break;
                }
            }
        }
        if (ica) std::cout << std::endl;
        std::cout << "Puzzle #" << ++ica << ":" << std::endl;
        if (no_final) std::cout << "This puzzle has no final configuration." << std::endl;
        else {
            for (int i = 1; i <= 5; ++i) {
                for (int j = 1; j <= 5; ++j) {
                    if (j>1) std::cout << ' ';
                    std::cout << board[i][j];
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
