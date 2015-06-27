// WA
//

# include <bits/stdc++.h>
# define testin freopen("in.txt", "r", stdin)

using namespace std;

const int maxn = 1e5+5;

int n, k;
std::vector<int> a[maxn];

int main()
{
    testin;
    int cc = 0, cp = 0;
    int mj = maxn, mi;
    scanf("%d%d", &n, &k);
    for (int i = 0, m; i < k; ++i) {
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            int t; scanf("%d", &t); a[i].push_back(t);
        }
    }

    for (int i = 0; i < k; ++i) {
        int t = a[i][ a[i].size() - 1 ];
        if (mj > t) {
            mj = t;
            mi = i;
        }
        for (int j = 0; j < a[i].size()-1; ++j) {
            if (a[i][j] != a[i][j+1]-1) {
                mj = std::min(mj, a[i][j]);
                if (mj > a[i][j]) {
                    mj = a[i][j];
                    mi = i;
                }
                break;
            }
        }
    }

    cc = k;
    for(int i = 0; i < k; ++i) {
        if (i == mi) {
            for (int j = 0; j < a[i].size() - 1; ++j) {
                if (a[i][j] == mj) {
                    cp += a[i].size() - 1 - j;
                    cc += a[i].size() - 1 - j;
                    break;
                }
            }
        } else {
            cp += a[i].size() - 1;
            cc += a[i].size() - 1;
        }
    }

    printf("%d\n", std::max(0,cc + cp - 1) );

    return 0;
}
