# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

char s[205];

int main()
{
    cin >> s;
    int i = 0;
    while (s[i]) {
        if (s[i]=='.') putchar('0');
        else if (s[i+1]=='.') {
            putchar('1');
            ++i;
        } else if (s[i+1]=='-') {
            putchar('2');
            ++i;
        }
        ++i;
    }
    cout << endl;

    return 0;
}
