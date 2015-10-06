/*
ID: yajunwf1
LANG: C++11
TASK: friday
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

int get(int y, int m, int d) {
    if (m < 3) m += 12, --y;
    int c = y / 100;
    y = y % 100;
    return ((y+y/4+c/4-2*c+(26*(m+1))/10+d-1) % 7 + 7) %7;
}

int c[7];

int main()
{
    rdio(friday);

    int n; cin >> n;
    for (int y = 1900; y <= 1900+n-1; ++y) {
        for (int m = 1; m <= 12; ++m) {
            ++c[ get(y, m, 13) ];
        }
    }
    int i = 6;
    do {
        cout << c[i];
        i = (i + 1) % 7;
        if (i != 6) cout << ' ';
    } while (i != 6);
    cout << endl;

    return 0;
}
