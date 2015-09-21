# include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

int n;
int a[maxn];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int c = 3; c <= n; ++c) {
        if (n%c==0) {
            int l = n / c;
            for (int i = 0, j; i < l; ++i) {
                for (j = 0; j < c; ++j) {
                    if (!a[j*l+i]) break;
                }
                if (j >= c) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}
