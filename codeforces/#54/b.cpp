# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e6+5;

int n;
bool isp[maxn];
int pt[maxn], pn;

void pre() {
    for (int i = 2; i < maxn; ++i) {
        if (!isp[i]) {
            pt[pn++] = i;
            for (lli j = i; j*i < maxn; ++j) {
                isp[j*i] = true;
            }
        }
    }
}

void solve() {
    cin >> n;
    cout << n;
    for (int i = 0; i < pn && n >= pt[i]; ++i) {
        while (n%pt[i] == 0) {
            n/=pt[i];
            cout << ' ' << n;
        }
    }
    cout << endl;
}

int main()
{
    pre();
    solve();

    return 0;
}
