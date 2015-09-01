# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int c[256];

int main()
{
    string he;
    string te;
    getline(cin, he);
    getline(cin, te);

    for (int i = 0; i < he.length(); ++i) ++c[ he[i] ];
    for (int i = 0; i < te.length(); ++i) {
        if (te[i] == ' ') continue;
        if (c[ te[i] ] <= 0) {
            cout << "NO" << endl;
            return 0;
        } else {
            --c[ te[i] ];
        }
    }
    cout << "YES" << endl;

    return 0;
}
