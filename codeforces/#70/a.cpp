# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool isv(int ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int co(char *str) {
    int ret = 0;
    for (int i = 0; str[i]; ++i) {
        if (isv(str[i])) ++ret;
    }
    return ret;
}

char s[105];
int t[3] = {5,7,5};

int main()
{
    for (int i = 0; i < 3; ++i) {
        gets(s);
        if (co(s) != t[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");

    return 0;
}
