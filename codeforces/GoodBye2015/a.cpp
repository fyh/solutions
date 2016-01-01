# include <bits/stdc++.h>
using namespace std;

int x;
char s[10], t[10];

int main()
{
    cin >> x >> s >> t;

    if (t[0] == 'w') {
        if (x == 5 || x == 6) cout << 53 << endl;
        else cout << 52 << endl;
    } else {
        if (x <= 29) cout << 12 << endl;
        else if (x <= 30) cout << 11 << endl;
        else cout << 7 << endl;
    }

    return 0;
}
