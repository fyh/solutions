# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

bool pm[maxn];
int pt[maxn], pn;
void pre() {
    for (lli i = 2; i < maxn; ++i) {
        if (!pm[i]) {
            pt[pn++] = i;
            for (lli j = i*i; j < maxn; j+=i) pm[j] = true;
        }
    }
}

lli n, m, k;

bool isd(lli x) {
    for (int i = 0; x>=2*k && x>pt[i] && i < pn; ++i) {
        if (x%pt[i] == 0) {
            return x >= k*pt[i];
        }
    }
    return false;
}

int main()
{
    pre();

    cin >> n >> m >> k;

    if (!isd(m)) {
        cout << "Marsel" << endl;
        return 0;
    }

    cout << (n%2==1 ? "Timur":"Marsel") << endl;

    return 0;
}
