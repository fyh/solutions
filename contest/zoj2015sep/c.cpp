# include <map>
# include <algorithm>
# include <cstdio>
# include <cstring>
typedef long long int lli;

const int maxn = 205;

int H;
int l[maxn], r[maxn];
char s[maxn];
int n;

void rm(int x) {
    r[ l[x] ] = r[x];
    l[ r[x] ] = l[x];
}
void rc(int x) {
    r[ l[x] ] = x;
    l[ r[x] ] = x;
}

const int hc = 1;
const lli hv[] = {201326611};
std::map<lli, int> hh;

lli build() {
    lli ret;
    int i = 0;
    for (int x = r[H]; x != H; x = r[x]) {
        int vl = (s[x]=='b' ? 1:0);
        ret = (ret*2 + vl) % hv[0];
        ++i;
    }
    return ret;
}

int sr(int cur) {
    lli hk = build();
    if (hh[hk]!=0) return hh[hk]-2;
    int ret = 0;
    for (int x = r[H]; x != H && x != l[H]; x = r[x]) {
        if (s[ l[x] ] == s[ r[x] ]) {
            rm(l[x]);
            rm(r[x]);
            ret = std::max(ret, sr(cur+2)+2);
            rc(r[x]);
            rc(l[x]);
        }
    }
    hh[hk] = ret + 2;
    return ret;
}

void solve() {
    scanf("%d", &n);
    scanf("%s", s+1);
    s[0] = '$';
    H = 0;
    for (int i = 0; i <= n; ++i) {
        l[i] = (i+n)%(n+1), r[i] = (i+1)%(n+1);
    }
    printf("%d\n", sr(0));
}

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        solve();
    }

    return 0;
}
