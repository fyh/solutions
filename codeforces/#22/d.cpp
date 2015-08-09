# include <bits/stdc++.h>
using namespace std;

# define testin freopen("in.txt", "r", stdin)

const int maxn = 2005;

int n;
int x[maxn], y[maxn], r[maxn];
bool nailed[maxn];

bool cmp(const int a, const int b)
{
    return y[a] < y[b];
}

int ans[maxn], cnt;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        if (x[i]>y[i]) swap(x[i],y[i]);
        r[i] = i;
    }
    sort(r, r+n, cmp);

    memset(nailed, false, sizeof(nailed));

    cnt = 0;
    for (int i = 0; i < n; ++i) {
        int t = r[i];
        if (!nailed[t]) {
            ans[cnt++] = y[t];
            for (int j = 0; j < n; ++j) {
                if (!nailed[j] && x[j]<=y[t]&&y[t]<=y[j]) {
                    nailed[j] = true;
                }
            }
            nailed[t] = true;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
