# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 5;

char s[maxn];
bool b[maxn][maxn];
int c[maxn];
int r[maxn];

bool ok = true;

void doit(char *t) {
    int x = t[0] - 'A';
    int y = t[2] - 'A';
    if (t[1] == '<') {
        ++b[y][x];
    } else {
        ++b[x][y];
    }
}

bool cmp(const int &x, const int &y) {
    return c[x] <= c[y];
}

int main()
{
    for (int i = 0; i < 3; ++i) r[i] = i;
    while (cin >> s) doit(s);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (b[i][j]) ++c[i];
        }
    }

    sort(r, r+3, cmp);
    if (ok && c[r[0]] == 0 && c[r[1]] == 1 && c[r[2]]==2) {
        for (int i = 0; i < 3; ++i) {
            cout << (char)(r[i]+'A');
        }
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
