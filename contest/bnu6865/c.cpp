// WA
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 5e6;

char w[maxn], p[maxn];
char st[maxn];
int sh[maxn];
int top;

const int HK = 1e9+7;
const int BASE = 131;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin >> w >> p) {
        top = 0;
        lli hw = 0;
        int n;
        lli pw = 1;
        for (n = 0; w[n]; ++n) {
            hw = (hw*BASE + w[n]) % HK;
            if(n > 0) pw = pw*BASE%HK;
        }
        lli hp = 0;
        for (int i = 0; p[i]; ++i) {
            st[top] = p[i];
            /*
            sh[top] = ((top ? sh[top-1]:0)*BASE + p[i]-'a'+1) % HK;
            if (top >= n) {
                sh[top] = ((sh[top] - (st[top-n]-'a'+1)*pw%HK)%HK + HK) % HK;
            }*/
            sh[top] = (top ? sh[top-1]:0);
            if (top >= n) sh[top] = ((sh[top] - pw*(st[top-n]-'a'+1) % HK) + HK) % HK;
            sh[top] = (sh[top]*BASE%HK + st[top]-'a'+1)%HK;
            sh[top] = (sh[top] + HK) % HK;
            ++top;
            if (top >= n && sh[top-1] == hw) top -= n;
        }
        st[top] = 0;
        puts(st);
    }

    return 0;
}
