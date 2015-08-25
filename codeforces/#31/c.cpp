// WA

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;

int n;
int l[maxn], r[maxn], id[maxn];

bool cmp(const int a, const int b) {
    return (l[a]==l[b]) ? (r[a]>r[b]) : (l[a]<=l[b]);
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        id[i] = i;
    }
    sort(id, id+n, cmp);

    int x = -1, y, c = 0, m = 0;
    for (int j = 0; j < n; ++j) {
        int i = id[j];
        if (x != -1) {
            if (r[x] > l[i]) {
                y = i;
                ++m;
            }
        }
        if (j+1<n && r[i] > l[id[j+1]]) {
            if (x == -1) x = i;
            ++c;
        }
    }
    if (c > 1) puts("0");
    else {
        if (c == 0) {
            cout << n << endl;
            for (int i = 0; i < n; ++i) {
                if (i) cout << ' ';
                cout << i+1;
            }
            cout << endl;
        } else {
            if (m > 1) cout << 1 << endl << x+1 << endl;
            else cout << 2 << endl << min(x, y)+1 << ' ' << max(x, y)+1 << endl;
        }
    }

    return 0;
}
