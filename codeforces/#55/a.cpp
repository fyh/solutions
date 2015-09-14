# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

char s[105];
int cu, cl;

int main()
{
    cin >> s;
    for (int i = 0; s[i]; ++i) {
        if (islower(s[i])) ++cl; else ++cu;
        s[i] = tolower(s[i]);
    }
    if (cu > cl) {
        for (int i = 0; s[i]; ++i) putchar(toupper(s[i]));
        puts("");
    } else puts(s);

    return 0;
}
