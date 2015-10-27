# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define speedup cin.tie(0), ios_base::sync_with_stdio(false)

const int maxn = 1e5+5;

int n, m;
int a[maxn];
int b[maxn];

int main()
{
    speedup;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < m; ++j) cin >> b[j];
    sort(a, a+n);
    sort(b, b+m);
    int c = 0, s = 0;
    while (s < n && c < m) {
        if (a[s] >= b[c]) {
            ++s;
            ++c;
        } else ++s;
    }

    cout << (c>=m ? "YES":"NO") << endl;

    return 0;
}
