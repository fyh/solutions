# include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

int n, m, v;
int a[maxn], ca;

int main()
{
    cin >> n >> m >> v;

    int L = n - 1;
    int H = (n-1)*(n-2)/2+1;

    bool fi = true;
    if (L<=m && m<=H) {
        for (int i = 1; i <= n; ++i) {
            if (i!=v) {
                if (fi) fi = false;
                else a[ca++] = i;
                cout << i << " " << v << endl;
                --m;
            }
        }
        if (!m) return 0;
        for (int i = 0; i < ca; ++i) {
            for (int j = i+1; j < ca; ++j) {
                cout << a[i] << " " << a[j] << endl;
                --m;
                if (!m) return 0;
            }
        }
    } else {
        puts("-1");
    }

    return 0;
}
