# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 305;

int n;
int a[maxn];
int b[maxn];
vector<int> aa;
vector<int> ab;
int ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            for (int j = i+1; j < n; ++j) {
                if (b[j] == a[i]) {
                    for (int k = j; k > i; --k) {
                        swap(b[k], b[k-1]);
                        ++ans;
                        aa.push_back(k);
                        ab.push_back(k+1);
                    }
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    for (int i = 0; i < aa.size(); ++i) {
        cout << aa[i] << ' ' << ab[i] << endl;
    }

    return 0;
}
