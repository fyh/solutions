# include <stdio.h>
# include <vector>
# include <algorithm>
# include <cmath>
# include <queue>

const int maxn = 1005;
const int INF = 0x3f3f3f3f;

int N, X, Y, MAX;
int x1[maxn], x2[maxn], h[maxn];
int ans;

int r[maxn];

bool cmp(const int x, const int y) {
    return h[x] > h[y];
}

struct pp{
    int x, y, w;
    pp(int _x, int _y, int _w)
        :x(_x),y(_y),w(_w) {}
};

void doit()
{
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d%d", &x1[i], &x2[i], &h[i]);
        if (x1[i] > x2[i]) std::swap(x1[i], x2[i]);
    }
    x1[0] = X, x2[0] = X, h[0] = Y;
    x1[N+1] = -INF, x2[N+1] = INF, h[N+1] = 0;
    ans = INF;

    for (int i = 0; i < N+2; ++i) r[i] = i;
    std::sort(r, r+N+2, cmp);

    ans = INF;
    std::queue< pp > Q;
    Q.push( pp(X, Y, 0) );

    while (Q.size()) {
        pp p = Q.front(); Q.pop();
        if (p.y == 0) ans = std::min(ans, p.w);
        for (int k = 0; k < N+2; ++k) {
            int i = r[k];
            if (x1[i]<=p.x && p.x<=x2[i] && p.y>h[i]&&p.y<=h[i]+MAX) {
                    if (h[i] == 0) {
                        ans = std::min(ans, p.w);
                    } else {
                        pp np1(x1[i], h[i], p.w+std::abs(p.x-x1[i]));
                        pp np2(x2[i], h[i], p.w+std::abs(p.x-x2[i]));
                        Q.push(np1);
                        Q.push(np2);
                    }
                    break;
            }
        }
    }
    printf("%d\n", ans + Y);
}

int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d%d%d", &N, &X, &Y, &MAX)) {
        doit();
    }

    return 0;
}
