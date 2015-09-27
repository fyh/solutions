# include <cstdio>
# define rep(x) for(int i = 0; i < (x); ++i)
# define rep1(y, x) for(int i = (y); i < (x); ++i)
int a[13];
bool vis[6];
int cnt(int x, int y)
{
    int ret = 0;
    rep(6) {
        if (vis[i]) continue;
        if ((a[2*i]==x&&a[2*i+1]==y) || (a[2*i+1]==x&&a[2*i]==y)) {
            ++ret;
            vis[i] = true;
            if (ret >= 2) break;
        }
    }
    return ret;
}
int main()
{
    while (scanf("%d", &a[0]) != EOF) {
        rep1(1,12) scanf("%d", &a[i]);
        int sum = 0;
        rep(12) sum += a[i];
        int x = a[0], y = a[1], z;
        bool ans = true;
        if (sum%4) ans = false;
        else {
            z = sum/4 - x - y;

            rep(12) if (a[i]!=x && a[i]!=y && a[i]!=z) {ans = false; break;}
            rep(6) vis[i] = false;
            if ( cnt(x,y)!=2 || cnt(y,z)!=2 || cnt(x,z)!=2) ans = false;
        }
        printf(ans ? "POSSIBLE\n":"IMPOSSIBLE\n");
    }
    return 0;
}
