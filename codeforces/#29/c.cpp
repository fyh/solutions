# include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

int idc;
map<int,int> vc;

int m = 1;
int id[maxn];
int in[maxn];

int n;
vector<int> g[maxn];

int doit(int x) {
    int t = vc[x];
    if (!t) {
        vc[x] = m;
        id[m++] = x;
    } else {
        ++in[t];
    }
    return vc[x];
}

void con(int x, int y) {
    g[x].push_back(y);
    g[y].push_back(x);
}

void run(int x, int f) {
    cout << id[x] << ' ';
    for (int i = 0; i < g[x].size(); ++i) {
        if (g[x][i] != f) {
            run(g[x][i], x);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        con(doit(x), doit(y));
    }
    for (int i = 1; i < m; ++i) {
        if (!in[i]) {
            run(i, 0);
            break;
        }
    }
    cout << endl;

    return 0;
}
