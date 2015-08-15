# include <bits/stdc++.h>
using namespace std;

int n;
char s[105];

void pr(int i, int x) {
    for (int j = 0; j < x; ++j) putchar(s[j+i]);
}

int main()
{
    cin >> n >> s;
    int i = 0;
    if (n&0x1) {
        pr(i, 3);
        i += 3;
        n -= 3;
    } else {
        pr(i, 2);
        i += 2;
        n -= 2;
    }
    while (n > 0) {
        putchar('-');
        pr(i, 2);
        i += 2;
        n -= 2;
    }
    putchar('\n');

    return 0;
}
