# include <string.h>
# include <string>
# include <map>
# include <iostream>
# include <stdio.h>

using namespace std;

# define testin freopen("in.txt", "r", stdin)
# define rep(n) for (int i = 0; i < n; ++i)
# define clr(x) memset(x, 0, sizeof(x))

map< string, string > mr;

int m, n;
string a, b;

int main()
{
    testin;
    cin >> n >> m;
    rep(m) {
        cin >> a >> b;
        mr[a] = b;
    }
    rep(n) {
        cin >> a;
        b = mr[a];
        int la = a.length();
        int lb = b.length();
        if (i) cout << ' ';
        if (la <= lb) cout << a;
        else cout << b;
    }
    cout << endl;

    return 0;
}
