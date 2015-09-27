/**************************************************************
    Problem: 1003
    User: fyh
    Language: C++
    Result: Accepted
    Time:28 ms
    Memory:884 kb
****************************************************************/
 
# include <cstdio>
# include <cstring>
# include <algorithm>
 
 
const int maxv = 35;
const int maxe = maxv * maxv / 2;
const int maxn = 115;
 
 
int n, m, K, e, d;
 
int w[maxe], v[maxe];
int first[maxv], next[maxe * 2];
 
int c[maxv][maxn];
 
 
void add_edge(int eid, int x, int y, int z)
{
    w[eid] = z;
    v[eid] = y;
    next[eid] = first[x];
    first[x] = eid;
    //   printf("first[%d] = %d, next[%d] = %d\n", x, first[x], first[x], next[first[x]]); fflush(stdout);
}
 
void init(void)
{
    scanf("%d%d%d%d", &n, &m, &K, &e);
    memset(first+1, -1, sizeof(first[0])*m);
    for (int i = 0, x, y, z; i < e; ++i) {
        scanf("%d%d%d", &x, &y, &z);
        add_edge(2*i, x, y, z);
        add_edge(2*i+1, y, x, z);
    }
    scanf("%d", &d);
    for (int i = 1; i <= m; ++i) memset(c[i], 0, sizeof(c[i][0])*(n+1));
    for (int i = 0, x, y, z; i < d; ++i) {
        scanf("%d%d%d", &z, &x, &y);
        for (int i = x; i <= y; ++i) c[z][i] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            c[i][j] += c[i][j-1];
        }       
    }
}
 
const int INF = 0x7FFFFFFF;
 
class node {
public:
    int value, key;
};
 
class bheap {
    node h[maxv];
    int pos[maxv];
    int sz;
public:
    void init(int cntNode) {
        h[sz = 0].value = -INF;
        memset(pos, -1, sizeof(pos[0])*(cntNode+1));
    }
    void decInsert(int key, int value) {
        node p = {value, key};
        int i, f;
        for (i = pos[key]<0 ? (++sz):(pos[key]); p.value < h[f=i>>1].value; i = f) {  // if i == 0
            h[i] = h[f];
            pos[h[i].key] = i;
        }
        h[i] = p;
        pos[h[i].key] = i;
    }
    int extract_min(void) {
        if (isempty() == true) return 0;
        int i, s, ret = h[1].key;
        node p = h[sz--];
        for (i = 1; (s=i<<1)<=sz; i = s) {
            if ((s+1)<=sz && h[s+1].value<h[s].value) ++s;
            if (h[s].value < p.value) {
                h[i] = h[s];
                pos[h[i].key] = i;
            } else break;
        }
        h[i] = p;
        pos[h[i].key] = i;
        return ret;
    }
    bool isempty() {
        return sz <= 0 ? true : false;
    }
};
 
bheap bh;
bool vis[maxv];
int dist[maxv];
 
void relax(int x, int ww, int bb, int ee) {
    if (c[x][bb-1]==c[x][ee] && !vis[x] && dist[x] > ww) {
        dist[x] = ww;
        bh.decInsert(x, ww);
    }
}
 
int dijkstra(int src, int dest, int x, int y)
{
    for (int i = 1; i <= m; ++i) dist[i] = INF;
    memset(vis+1, false, sizeof(vis[0])*m);
    dist[src] = 0;
    bh.init(m);
    for ( bh.decInsert(src, 0) ; !bh.isempty() ; ) {
        int cur = bh.extract_min();
        //      printf("%d\n", cur); fflush(stdout);
        vis[cur] = true;
        if (cur == dest) return dist[cur];
        for (int eid = first[cur]; eid != -1; eid = next[eid]) {
            //     printf("eid = %d\n", eid);
            relax(v[eid], w[eid] + dist[cur], x, y);
        }
    }
    return INF;
}
 
int f[maxn];
int minDist[maxn][maxn];
 
void solve()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            minDist[i][j] = dijkstra(1, m, i, j);
            //     printf("minDist[%d][%d] =  %d\n", i, j, minDist[i][j]); fflush(stdout);
        }
    }
    f[0] = -K;
    for (int i = 1; i <= n; ++i) f[i] = INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (minDist[j+1][i] < INF) f[i] = std::min(f[i], f[j]+minDist[j+1][i]*(i-j)+K);
        }
    }
    printf("%d\n", f[n]);
}
 
int main()
{
    init();
    solve();
 
    return 0;
}