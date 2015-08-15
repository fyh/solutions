# include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int pr[][3] = {
    0, 1, 2,
    0, 2, 1,
    1, 0, 2,
    1, 2, 0,
    2, 0, 1,
    2, 1, 0
};


int l[3];
char s[3][maxn];

const int hk[] = {53, 131, 6151, 31, 3, 2, 98317}, hc = 7, base = 10;
int po[maxn];
int cnt[maxn];

bool con(int x, int y) {
    if (l[x] < l[y]) return false;
    memset(cnt, 0, sizeof(cnt));
    po[0] = 1;
    for (int c = 0; c < hc; ++c) {
        int hs = 0, hg = 0;
        for (int i = 1; i < maxn; ++i) po[i] = (po[i-1]*base)%hk[c];
        for (int i = 0; i < l[y]; ++i) {
            hs = (hs*base + s[x][i]) % hk[c];
            hg = (hg*base + s[y][i]) % hk[c];
        }
        for (int i = 0; i+l[y]-1 < l[x]; ++i) {
            if (hs == hg) ++cnt[i];
            hs = (hs - s[x][i]*po[l[y]-1])*base%hk[c] + s[x][i+l[y]];
            hs = (hs%hk[c] + hk[c])%hk[c];
        }
    }
    for (int i = 0; i+l[y]-1 < l[x]; ++i) {
        if (cnt[i] == hc) {
            // if always lucky just ..
            return true;
        }
    }
    return false;
}

int com(int x, int y) {
    memset(cnt, 0, sizeof(cnt));
    for (int c = 0; c < hc; ++c) {
        po[0] = 1;
        for (int i = 1; i < maxn; ++i) po[i] = (po[i-1]*base)%hk[c];
        int hx = 0, hy = 0;
        for (int i = 0; i < min(l[x], l[y]); ++i) {
            hx = (hx + po[i]*s[x][l[x]-1-i]) % hk[c];
            hy = (hy*base + s[y][i]) % hk[c];
            if (hx == hy) ++cnt[i];
        }
    }
    for (int i = min(l[x], l[y])-1; i >= 0; --i) {
        if (cnt[i] == hc) return i + 1;
    }
    return 0;
}

int solve(int x, int y, int z) {

    if (con(y,x)) return con(z,y) ? l[z]:l[y]+l[z]-com(y,z);
    else {
        if (con(z,y)) return l[z]+l[x]-com(x,z);
        else return l[x]+l[y]+l[z]-com(x,y)-com(y,z);
    }}

int main()
{
    // freopen("in.data", "r", stdin);
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
        l[i] = strlen(s[i]);
    }
    int ans = maxn * 3;
    for (int i = 0; i < 6; ++i) {
        ans = min(ans, solve(pr[i][0], pr[i][1], pr[i][2]));
    }
    cout << ans << endl;

    return 0;
}
