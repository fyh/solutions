# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 15;

int n;
int a[N], b[N], c[N];
int ans = 0;

set<int>g;

int t[4];
bool ok(int num) {
    if (g.count(num) > 0) return false;
    for (int i = 0; i < 4; ++i) {
        t[i] = num%10;
        num/=10;
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 4; ++j) {
            if (t[i] == t[j]) return false;
        }
    }
    return true;
}

int s[4];
bool jd(int num) {
    int tmp = num;
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        num = tmp;
        int cx = 0, cy = 0;
        for (int j = 0; j < 4; ++j) {
            s[j] = cur%10; cur/=10;
            t[j] = num%10; num/=10;
            if (s[j]==t[j]) ++cx;
        }
        if (cx != b[i]) return false;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (s[j] == t[k] && j != k) ++cy;
            }
        }
        if (cy != c[i]) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i], g.insert(a[i]);

    int cnt = 0;
    for (int i = 100; i < 10000; ++i) {
        if (ok(i) && jd(i)) {
            ++cnt;
            ans = i;
            if (cnt > 1) break;
        }
    }

    if (cnt > 1) puts("Need more data");
    else if (cnt == 0) puts("Incorrect data");
    else printf("%04d\n", ans);

    return 0;
}

