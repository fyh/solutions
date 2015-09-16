# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 105;

char s[N], t[N];

int main()
{
    cin >> s >> t;
    for (int i = 0; s[i]; ++i) {
        if (s[i]!=t[i]) cout << '1';
        else cout << '0';
    }
    cout << endl;

    return 0;
}
