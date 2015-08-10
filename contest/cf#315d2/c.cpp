# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const lli maxn = 1300005;

lli pi[maxn];
lli rub[maxn];

bool isp[maxn];

char s[10];
int get(int x) {
    int n = 0;
    while (x > 0) {
        s[n++] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n-1-i]) return 0;
    }
    return 1;
}

void pre() {
    rub[0] = 0, rub[1] = 1;
    for (lli i = 2; i < maxn; ++i) {
        rub[i] = rub[i-1] + get(i);
        pi[i] = pi[i-1];
        if (!isp[i]) {
            ++pi[i];
            for (lli j = i; j*i < maxn; ++j) {
                isp[j*i] = true;
            }
        }
    }
}

# define testout freopen("out.txt", "w", stdout)

int main()
{
    pre();

    lli p, q;
    cin >> p >> q;

    bool fi = false;
    for (int i = maxn-1; i >= 0; --i) {
        if (pi[i]*q <= p*rub[i]) {
            fi = true;
            cout << i << endl;
            break;
        }
    }
    if (!fi) puts("Palindromic tree is better than splay tree");

    return 0;
}
