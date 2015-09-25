# include <map>
# include <utility>
# include <algorithm>
# include <cstdio>
# include <cstring>

const int maxn = 10005;
const int maxm = 20005;
const int maxq = 50005;

int n, m, q;
int power[maxn];
int u[maxm], v[maxm];
bool des[maxm];
int query[maxq][3];
int p[maxn];

std::map< std::pair<int, int>, int >mp;

int find(int x) {
    return x==p[x] ? x:p[x]=find(p[x]);
}
void join(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return ;
    if (x > y) std::swap(x, y);
    if (power[x] < power[y]) p[x] = y;
    else p[y] = x;
}
# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;

    bool first = true;

    while (scanf("%d", &n) != EOF) {
        mp.clear();
        for (int i = 0; i < n; ++i) scanf("%d", &power[i]);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u[i], &v[i]);
            if (u[i] > v[i]) std::swap(u[i], v[i]);
            mp[std::make_pair(u[i], v[i])] = i+1;
        }
        memset(des, false, sizeof(des[0])*m);
        scanf("%d", &q);
        char od[15];
        for (int i = 0, x, y; i < q; ++i) {
            scanf("%s%d", od, &x);
            if (od[0] == 'q') {
                query[i][0] = 0;
                query[i][1] = x;
            } else {
                scanf("%d", &y);
                if (x > y) std::swap(x, y);
                int t = mp[ std::make_pair(x,y) ] - 1;
                if (t >= 0) des[t] = true;
                query[i][0] = 1;
                query[i][1] = x;
                query[i][2] = y;
            }
        }
        for (int i = 0; i < n; ++i) p[i] = i;
        for (int i = 0; i < m; ++i) {
            if (!des[i]) {
                join(u[i], v[i]);
            }
        }
        for (int i = q-1; i >= 0; --i) {
            if (!query[i][0]) {
                int t = find( query[i][1] );
                if (power[t] <= power[ query[i][1] ]) t = -1;
                query[i][2] = t;
            } else {
                join( query[i][1], query[i][2] );
            }
        }
        if (first) first = false;
        else printf("\n");
        for (int i = 0; i < q; ++i) {
            if (!query[i][0]) printf("%d\n", query[i][2]);
        }
    }

    return 0;
}
