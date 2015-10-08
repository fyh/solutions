# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5;

bool pm[maxn];
int pt[maxn], pn;
void pre() {
    pm[0] = true;
    pm[1] = true;
    for (lli i = 2; i < maxn; ++i) {
        if (!pm[i]) {
            pt[pn++] = i;
            for (lli j = i*i; j < maxn; j+=i) {
                pm[j] = true;
            }
        }
    }
}

bool isp(int x) {
    if (x < maxn) return pm[x] == false;
    for (int i = 0; i < pn && x >= pt[i]; ++i) {
        if (x%pt[i] == 0) return false;
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    pre();

    int n; cin >> n;

    if (isp(n)) {
        cout << 1 << endl << n << endl;
    } else {
        for (int i = n; i > 0; i -= 2) {
            if (isp(i)) {
                int t = n - i;
                for (int j = 0; j < pn && t >= pt[j]; ++j) {
                    if (isp(t - pt[j])) {
                        cout << 3 << endl << i << ' ' << pt[j] << ' ' << t-pt[j] << endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
