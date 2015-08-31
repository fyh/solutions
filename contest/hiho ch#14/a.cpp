# include <bits/stdc++.h>
using namespace std;

const int maxn = 55;

bool jd(int x, int typ, int v) {
    switch (typ) {
        case 0: {
            return x < v;
            break;
        }
        case 1: {
            return x <= v;
            break;
        }
        case 2: {
            return x == v;
            break;
        }
        case 3: {
            return x > v;
            break;
        }
        case 4: {
            return x >= v;
            break;
        }
    }
}

int n;
int c[maxn], t[maxn];
int chk(int x, int v) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (jd(x, t[i], v*c[i])) ++ret;
    }
    return ret;
}

int get_type(char *x) {
    if (x[0] == '=') return 2;
    if (strlen(x) >= 2) {
        return x[0]=='<' ? 1:4;
    }
    return x[0]=='<' ? 0:3;
}

int main()
{
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            char x[5], y[5];
            cin >> x >> y >> c[i];
            t[i] = get_type(y);
        }
        int ans = 0;
        for (int i = -1; i <= 1005; ++i) {
            ans = max(ans, chk(2*i+1, 2));
            ans = max(ans, chk(i, 1));
        }
        cout << ans << endl;
    }
}
