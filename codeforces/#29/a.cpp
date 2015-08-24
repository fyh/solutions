# include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int n;
int x[maxn], d[maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i] >> d[i];
    bool ok = false;
    for (int i = 0; !ok && i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (x[i]+d[i]==x[j] && x[j]+d[j]==x[i]) {
                ok = true;
                break;
            }
        }
    }
    cout << (ok ? "YES":"NO") << endl;

    return 0;
}
