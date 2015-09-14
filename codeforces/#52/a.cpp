# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;
string str;
string al[] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE", "$"};
map<string, int> m;

int get(string s) {
    int ret = 0;
    for (int i = 0; i < s.length(); ++i) {
        ret = ret * 10 + s[i] - '0';
    }
    return ret;
}

int main()
{
    for (int i = 0; al[i][0] != '$'; ++i) m[ al[i] ] = 2;

    int ans = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        if (isdigit(str[0])) {
            if (get(str) < 18) ++ans;
        } else if (m[str] > 0) ++ans;
    }

    cout << ans << endl;

    return 0;
}
