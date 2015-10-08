# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;
char *s = "ROYGBIV";

// 12345671234

int main()
{
    cin >> n;
    for (int i = 0; i < n/7; ++i) cout << s;
    for (int i = 0; i < n%7; ++i) {
        if (n%7 <= 3) cout << s[i+3];
        else cout << s[i];
    }
    cout << endl;

    return 0;
}
