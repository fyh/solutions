# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 105;

int n, m;
int t[maxn];
int c[maxn];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int l, r, ti, ci;
        cin >> l >> r >> ti >> ci;
        for (int j = l; j <= r; ++j) {
            if (t[j]==0 || ti<t[j]) {
                t[j] = ti;
                c[j] = ci;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += c[i];
    cout << sum << endl;

    return 0;
}
