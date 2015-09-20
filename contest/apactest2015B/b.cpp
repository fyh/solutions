# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ull;

# define testin freopen("B-large.in", "r", stdin)
# define testout freopen("ou.txt", "w", stdout)

const int maxn = 2005;

int np, ne, nt;
lli a[maxn], b[maxn], c[maxn];
lli x[maxn*maxn];
lli y[maxn*maxn];
int P, Q;
map<lli, set<lli> > A;

lli Gcd(lli aa, lli bb)
{
    if (bb==0) return aa;
    return Gcd(bb, aa%bb);
}

void solve()
{
    for (int i = 0; i < np; ++i) {
        for (int j = 0; j < nt; ++j) {
            lli x = P * c[j];
            lli y = Q * a[i];
            lli z = Gcd(x, y);
            if (A.count(x/z)>0 && A[x/z].count(y/z)>0) {
                cout << "Yes" << endl;
                return ;
            }
        }
    }
    cout << "No" << endl;
}

int main()
{
    testin;
    testout;
    int T;
    cin >> T;
    for (int ica = 1; ica <= T; ++ica) {
        cout << "Case #" << ica << ":" << endl;
        cin >> np >> ne >> nt;
        for (int i = 0; i < np; ++i) cin >> a[i];
        for (int i = 0; i < ne; ++i) cin >> b[i];
        for (int i = 0; i < nt; ++i) cin >> c[i];
        A.clear();
        for (int i = 0; i < ne; ++i) {
            for (int j = i+1; j < ne; ++j) {
                lli tmp = Gcd(b[i], b[j]);
                A[ b[i]/tmp ].insert( b[j]/tmp );
                A[ b[j]/tmp ].insert( b[i]/tmp );
            }
        }
        int M;
        cin >> M;
        for (int i = 0; i < M; ++i) {
            cin >> P >> Q;
            lli tg = Gcd(P, Q);
            P/=tg, Q/=tg;
            solve();
        }
    }

    return 0;
}
