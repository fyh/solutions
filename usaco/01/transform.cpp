/*
ID: yajunwf1
LANG: C++11
TASK: transform
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

const int maxn = 15;

int n;
char s[maxn][maxn], t[maxn][maxn];

bool chk() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i][j] != t[i][j]) return false;
        }
    }
    return true;
}

char h[maxn][maxn];

void rot(int ti) {
    for (int x = 0; x < ti; ++x) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                h[i][j] = t[n+1-j][i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                t[i][j] = h[i][j];
            }
        }
    }
}

void rot2(int ti) {
    for (int x = 0; x < ti; ++x) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                h[i][j] = t[j][n+1-i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                t[i][j] = h[i][j];
            }
        }
    }
}

void refl() {
    int ha = n/2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= ha; ++j) {
            swap(t[i][j], t[i][n+1-j]);
        }
    }
}

bool doit(int od) {
    switch(od) {
        case 0: case 1: case 2: {
            rot(od+1);
            if (chk()) return true;
            rot2(od+1);
            break;
        }
        case 3: {
            refl();
            if (chk()) return true;
            refl();
            break;
        }
        case 4: {
            refl();
            for (int i = 1; i < 4; ++i) {
                rot(i);
                if (chk()) return true;
                rot2(i);
            }
        }
    }
    return false;
}

int main()
{
    rdio(transform);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> t[i]+1;
    for (int i = 1; i <= n; ++i) cin >> s[i]+1;

    bool same = chk();

    for (int i = 0; i < 5; ++i) {
        if (doit(i)) {
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << (same ? 6:7) << endl;

    return 0;
}
