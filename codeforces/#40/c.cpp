# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

char e[105];

void go(char *s, int n) {
    bool a = false;
    for (int i = 0; i < n; ++i) {
        if (i+2<n&&s[i]=='d'&&s[i+1]=='o'&&s[i+2]=='t') {
            cout << '.';
            i += 2;
        } else if (i+1<n&&!a && s[i]=='a'&&s[i+1]=='t') {
            cout << '@';
            a = true;
            i += 1;
        } else {
            cout << (char)s[i];
        }
    }
}

int main()
{
    cin >> e;

    int n = strlen(e);

    cout << (char)e[0];
    go(e+1, n-2);
    cout << (char)e[n-1];

    return 0;
}
