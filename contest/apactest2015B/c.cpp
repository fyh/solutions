# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ull;

# define testin freopen("C-small-attempt3.in", "r", stdin)
# define testout freopen("ou.txt", "w", stdout)

const int maxn = 1005;

int f[maxn];

bool isp[maxn];
int pt[maxn], pn = 0;

void prep()
{
    memset(isp, false, sizeof(isp));
    isp[0] = isp[1] = true;
    for (int i = 2; i < maxn; ++i) {
        if (!isp[i]) {
            pt[pn++] = i;
            for (int j = i*i; j < maxn; j+=i) {
                isp[j] = true;
            }
        }
    }
}

int ds(int cur)
{
    int ret = 0;
    while (cur > 0) {
        ret += cur%10;
        cur /= 10;
    }
    return ret;
}

int doit(int c)
{
    if (f[c] != 0) return f[c];
    if (c == 1 || ds(c)==1 || !isp[ds(c)]) {
        return f[c] = -1;
    }
    else if (!isp[c]) {
        return f[c] = 1;
    }
    else {
        for (int i = 0; i < pn; ++i) {
            int tm = c;
            if (tm%pt[i] == 0) {
                while (tm%pt[i] == 0) tm/=pt[i];
                if (-1==doit(tm)) {
                    return f[c] = 1;
                }
            }
        }
        return f[c] = -1;
    }
}

void pre()
{
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= maxn; ++i) {
        doit(i);
    }
}

int main()
{
    testin;
    testout;
    prep();
    pre();
    int T;
    cin >> T;
    for (int ica = 1; ica <= T; ++ica) {
        cout << "Case #" << ica << ": ";
        int n;
        cin >> n;
        cout << (f[n]==-1 ? "Seymour":"Laurence") << endl;
    }

    return 0;
}
