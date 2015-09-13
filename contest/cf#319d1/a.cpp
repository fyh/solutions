# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1100;

int pt[maxn], pn;
int n;

void pre() {
    for (int i = 2; i < maxn; ++i) {
        bool isp = true;
        for (int j = 2; j < i; ++j) {
            if (i%j == 0) {
                isp = false;
                break;
            }
        }
        if (isp) pt[pn++] = i;
    }
}

vector<int> ans;

int main()
{
    pre();

    cin >> n;
    for (int i = 0; pt[i] <= n; ++i) {
        int base = pt[i];
        while (base <= n) {
            ans.push_back(base);
            base *= pt[i];
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
