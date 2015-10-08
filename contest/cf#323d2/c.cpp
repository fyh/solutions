# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 505;

int n;
map<int,int> M;
int ans[maxn], top;

int gcd(int a, int b) {return !b ? a:gcd(b, a%b);}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n*n; ++i) {
        int x; cin >> x;
        ++ M[x];
    }

    while (top < n) {
        if (M.rbegin()->second == 0) {
            M.erase( M.rbegin()->first );
            continue;
        }
        ans[top] = M.rbegin()->first;
        --M[ ans[top] ];
        for (int i = 0; i < top; ++i) {
            int t = gcd(ans[top], ans[i]);
            M[t] -= 2;
        }
        ++top;
    }

    for (int i = 0; i < top; ++i) cout << ans[i] << ' ';

    cout << endl;

    return 0;
}
