# include <iostream>
# include <map>
# include <vector>
# include <queue>
# include <cstring>
# include <algorithm>
# include <cstdio>
using namespace std;
typedef long long int lli;
# define testin freopen("in.txt", "r", stdin)

bool first = true;
bool space = false;

char buf[10005];
int cnt = 0;

int main()
{
    //testin;
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            if (cnt > 0 && buf[cnt-1]==' ') continue;
        }
        if (isalpha(ch)) ch = tolower(ch);
        buf[cnt++] = ch;
    }
    buf[cnt] = 0;

    for (int i = 0; i < cnt; ++i) {
        ch = buf[i];
        if (isalpha(ch)) {
            if (first) {
                putchar(toupper(ch));
                first = false;
            } else {
                putchar(ch);
            }
            space = true;
        } else if (ch == ' ') {
            if (buf[i+1] == ',' || buf[i+1] == '.') {
                space = false;
            }
            if (space) {
                putchar(' ');
                space = false;
            }
        } else {
            putchar(ch);
            space = true;
            if (ch == '.') {
                first = true;
            }
            if (ch == '\n') {
                space = false;
                first = true;
            }
        }
    }

    return 0;
}
