# include <iostream>
# include <string.h>
using namespace std;

const int maxn = 105;

int n, m;
bool ex;

int main()
{
    while (cin >> n >> m) {
        ex = false;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);
            if (u==1 && v==n) ex = true;
        }
        if (ex) {
            cout << 1 << ' ' << n*(n-1)/2 << endl;
        } else {
            cout << 1 << ' ' <<  1 << endl;
        }
    }

    return 0;
}
