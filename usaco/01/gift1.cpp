/*
ID: yajunwf1
LANG: C++11
TASK: gift1
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

int n;
string na[10];
int mo[10];
map<string, int> id;

int main()
{
    rdio(gift1);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> na[i];
        id[ na[i] ] = i;
        mo[i] = 0;
    }
    string tm;
    while (cin >> tm) {
        int m, c;
        cin >> m >> c;
        if (c == 0) {
            mo[ id[tm] ] -= m;
            continue;
        } else {
            mo[ id[tm] ] -= m-m%c;
        }
        for (int i = 0; i < c; ++i) {
            string cur; cin >> cur;
            mo[ id[cur] ] += m/c;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << na[i] << ' ' << mo[i] << endl;
    }

    return 0;
}
