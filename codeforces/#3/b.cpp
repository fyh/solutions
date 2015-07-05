# include <stdio.h>
# include <map>
# include <queue>

const int maxn = 1e5+5;
typedef std::pair<int,int> pii;
std::priority_queue<pii> Q1, Q2;
int n, v, sw = 0, sv = 0;
int sol[maxn], cc = 0;
std::map<int, pii> mp;

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &v);
    for (int i = 0; i < n; ++i) {
        int ww, vv;
        scanf("%d%d", &ww, &vv);
        sw += ww;
        sv += vv;
        if (ww == 1) Q1.push( std::make_pair(vv, i+1) );
        else Q2.push( std::make_pair(vv, i+1) );
    }

    if (sw <= v) {
        printf("%d\n", sv);
        for (int i = 1; i <= n; ++i) printf("%d ", i);
        printf("\n");
    } else {
        int ans = 0;
        if (v%2 == 1) {
            if (Q1.size() > 0) {
                pii p = Q1.top(); Q1.pop();
                ans += p.first;
                sol[cc++] = p.second;
            }
            --v;
        }
        int id = n;
        while (Q1.size()>1) {
            pii p1 = Q1.top(); Q1.pop();
            pii p2 = Q1.top(); Q1.pop();
            Q2.push( std::make_pair(p1.first+p2.first, ++id) );
            mp[id] = std::make_pair(p1.second, p2.second);
        }
        while (v >= 2) {
            pii p = Q2.top(); Q2.pop();
            ans += p.first;
            if (p.second <= n) sol[cc++] = p.second;
            else {
                pii q = mp[p.second];
                sol[cc++] = q.first;
                sol[cc++] = q.second;
            }
            v -= 2;
        }
        printf("%d\n", ans);
        for (int i = 0; i < cc; ++i) {
            printf("%d ", sol[i]);
        }
        printf("\n");
    }

    return 0;
}
