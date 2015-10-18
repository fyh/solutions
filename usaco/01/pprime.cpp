/*
ID: yajunwf1
LANG: C++11
TASK: pprime
*/
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

int a, b;

set<int> s;
lli po(lli a, lli n, lli m) {
    lli ans = 1;
    for (lli h = a; n > 0; n >>= 1, h = h*h%m) {
        if (n&0x1) ans = ans*h%m;
    }
    return ans;
}

bool miller_rabin(lli x) {
    if (x < 2) return false;
    if (x%2 == 0) return x==2;
    if (x%3 == 0) return x==3;
    if (x%5 == 0) return x==5;
    // error < 1-(1/4)^30
    for (int i = 1; i < 30; ++i) {
        if ( po(rand()%(x-1)+1,x-1,x) != 1) return false;
    }
    return true;
}

char str[15];
char h[15];
lli get(int i, int t) {
    lli r = i;
    for (int j = 0; i > 0; ++j, i/=10) {
        if (!j && !t) continue;
        r = r*10+i%10;
    }
    return r;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    rdio(pprime);
    cin >> a >> b;

    for (int i = 1, x=0, y=0; x<=b; ++i) {
        x = get(i, 0);
        y = get(i, 1);
        if (a<=x&&x<=b && miller_rabin(x)) s.insert(x);
        if (a<=y&&y<=b && miller_rabin(y)) s.insert(y);
    }

    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
