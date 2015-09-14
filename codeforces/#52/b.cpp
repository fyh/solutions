# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;
vector<int> co;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; co.push_back(x);
    }

    int l, r;
    for (int i = 0; i < n; ++i) {
        if (co[i] != i+1) {
            l = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; --i) {
        if (co[i] != i+1) {
            r = i;
            break;
        }
    }

    bool ok = true;
    if (l < r) {
        reverse(co.begin()+l, co.begin()+r+1);
        for (int i = 0; i < n; ++i) {
            if (co[i] != i+1) {
                ok = false;
                break;
            }
        }
    } else ok = false;

    if (!ok) l = r = 0;
    else ++l, ++r;
    cout << l << ' ' << r;

    return 0;
}
