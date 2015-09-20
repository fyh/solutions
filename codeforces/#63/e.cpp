# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

map<int,int> M;
map<int,int> M;

int n, k;
int a[maxn];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < k-1; ++i) {
        M[ a[i] ] ++;
    }
    for (int i = k-1; i < n; ++i) {
        M[ a[i] ] ++;
        bool fi = false;
        for (auto it = M.rbegin(); it != M.rend(); ++it) {
            if (it->second == 1) {
                fi = true;
                cout << it->first << endl;
                break;
            }
        }
        if (!fi) cout << "Nothing" << endl;
        --M[ a[i-k+1] ];
    }

    return 0;
}
