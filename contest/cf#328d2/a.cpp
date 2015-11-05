# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

char s[10][10];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for (int i = 1; i <= 8; ++i) {
        cin >> s[i]+1;
    }

    int ax = 8, ay = 8;
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            if (s[i][j] == 'W') {
                bool ok = true;
                for (int k = i-1; k >= 1; --k) {
                    if (s[k][j] != '.') {
                        ok = false;
                        break;
                    }
                }
                if (ok) ax = min(ax, i-1);
            } else if (s[i][j] == 'B') {
                bool ok = true;
                for (int k = i+1; k <= 8; ++k) {
                    if (s[k][j] != '.') {
                        ok = false;
                        break;
                    }
                }
                if (ok) ay = min(ay, 8-i);
            }
        }
    }

    if (ax <= ay) cout << 'A' << endl;
    else cout << 'B' << endl;

    return 0;
}
