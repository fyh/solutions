# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ull;

# define testin freopen("in.txt", "r", stdin)
# define testout freopen("ou.txt", "w", stdout)

map<lli,int> M;

const int maxn = 1e8;

bool np[maxn];
int pt[maxn];
int pn = 0;

void pre() {
    np[1] = np[0] = true;
    for (lli i = 2; i < maxn; ++i) {
        if (!np[i]) {
            pt[pn++] = i;
            for (lli j = i; j*i < maxn; ++j) {
                np[j*i] = true;
            }
        }
    }
}

int ds(lli x) {
    int ret = 0;
    while (x > 0) {
        ret += x%10;
        x /= 10;
    }
    return ret;
}

int dp(lli x) {
    if (M.count(x)) return M[x];
    if (x==1 || ds(x)==1 || !np[ds(x)]) {
        return M[x] = -1;
    }
    for (int i = 0; pt[i] <= x && i < pn; ++i) {
        if (x%pt[i] == 0) {
            lli tmp = x;
            while (tmp%pt[i] == 0) tmp /= pt[i];
            if (dp(tmp) == -1) return M[x] = 1;
        }
        return M[x] = -1;
    }
}

int main()
{
    testin;
    // testout;
   // pre(); cout << pn << endl;
    int T; cin >> T; cout << T << endl;
    for (int ica = 1; ica <= T; ++ica) {
      //  cout << "Case #" << ica << ":";
        lli x;
       // cout << (dp(x)==1 ? "Laurence":"Seymour") << endl;
    }

    return 0;
}

