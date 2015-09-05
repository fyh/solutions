# include <iostream>
# include <vector>
# include <map>
# include <string.h>
# include <queue>
using namespace std;

typedef long long int lli;

const int maxn = 105;
const int maxm = 1e5+5;

int n;
int a[maxn];

int pt[maxm], pn;
bool isp[maxm];

void pre() {
    for (lli i = 2; i < maxm; ++i) {
        if (!isp[i]) {
            pt[pn++] = i;
            for (lli j = i; i*j < maxm; ++j) {
                isp[j*i] = true;
            }
        }
    }
}

void solve() {
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > Q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        while (a[i] > 1) {
            for (int j = 0; pt[j] <= a[i] && j < pn; ++j) {
                while (a[i] % pt[j] == 0) {
                    a[i] /= pt[j];
                    Q.push(pt[j]);
                }
            }
        }
    }
    if (Q.size() < 2) {
        cout << -1 << endl;
    } else {
        lli x = Q.top(); Q.pop();
        x *= Q.top(); Q.pop();
        cout << x << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    pre();

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
