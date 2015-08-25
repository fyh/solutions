#include <bits/stdc++.h>
using namespace std;

char s[205];

int main()
{
    cin >> s;
    int len = strlen(s);

    bool ok = true;
    int pre = -2;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '@') {
            if (i-pre <= 2 || !s[i+1]) {
                ok = false;
                break;
            }
            pre = i;
        }
    }

    if (!ok || pre < 0) puts("No solution");
    else {
        bool first = true;
        for (int i = 0; s[i]; ++i) {
            putchar(s[i]);
            if (s[i]=='@') {
                putchar(s[++i]);
                if(pre!=i-1) putchar(',');
            }
        }
        cout << endl;
    }

    return 0;
}
