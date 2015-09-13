# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

char s[105];
char* t = "hello";
int cnt = 0;

int main()
{
    cin >> s;

    bool ok = false;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == t[cnt]) {
            ++cnt;
            if (cnt >= 5) {
                ok = true;
                break;
            }
        }
    }
    cout << (ok ? "YES":"NO") << endl;

    return 0;
}
