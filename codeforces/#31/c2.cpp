// AC
# include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;

int n;
int l[maxn], r[maxn], id[maxn];
int ans[maxn], m;

bool cmp(const int a, const int b) {
    return l[a] <= l[b];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {cin >> l[i] >> r[i]; id[i] = i;}
    sort(id, id+n, cmp);

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int c = id[i];
        if (i+1<n && r[c] > l[ id[i+1] ]) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << n << endl;
        for (int i = 0; i < n; ++i) cout << i+1 << ' ';
        cout << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                int c = id[j];
                if (c == i) continue;
                if (id[j+1] == i) {
                    if (j+2 < n && r[c] > l[ id[j+2] ]) {
                        ok = false;
                        break;
                    }
                } else {
                    if (j+1 < n && r[c] > l[ id[j+1] ]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) ans[m++] = i+1;
        }
        cout << m << endl;
        for (int i = 0; i < m; ++i) cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
