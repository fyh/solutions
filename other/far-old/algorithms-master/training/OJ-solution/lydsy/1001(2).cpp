// binary_heap
// 
# include <cstdio>
# include <cstring>
# include <algorithm>

const int INF = 0x7FFFFFFF;
const int maxv = 2000005 + 2;
const int maxe = 6*1005*1005+4*1005;

int N, M;
int n, m;
int w[maxe], v[maxe];
int first[maxv], next[maxe];

class node {
public:
    int value, key;
};

class bheap {
    node h[maxv];
    int pos[maxv];
    int sz;
public:
    void init(int cnt) { h[sz=0].value = -INF; memset(pos, -1, sizeof(pos[0])*(cnt+1));}
    void decInsert(int key, int value) {
        node p = {value, key};
        int i, f;
        for (i = pos[key]<0 ? ++sz:pos[key]; value < h[f=i>>1].value; i = f) {
            h[i] = h[f];
            pos[h[i].key] = i;
        }
        h[i] = p;
        pos[key] = i;
    }
    int extract_min(void) {
        int i, s, ret = h[1].key;
        node p = h[sz--];
        for (i = 1; (s=i<<1) <= sz; i = s) {
            if ((s+1)<=sz && h[s+1].value < h[s].value) ++s;
            if (h[s].value < p.value) {
                h[i] = h[s];
                pos[h[i].key] = i;
            } else break;
        }
        h[i] = p;
        pos[h[i].key] = i;
        return ret;
    }
    bool empty() { return sz<=0; }
};

bool vis[maxv];
int dist[maxv];
bheap bh;

void relax(int x, int ww) { if (!vis[x] && dist[x]>ww) dist[x] = ww, bh.decInsert(x, ww); }
int dijkstra(int src, int dest)
{
    if (!M || !N) {
        int ret = INF;
        for (int i = 0; i < m; ++i) ret = std::min(ret, w[i]);
        return ret;
    }
    memset(vis, false ,sizeof(vis[0])*n);
    for (int i = 0; i < n; ++i) dist[i] = INF;
    dist[src] = 0;
    bh.init(n);
    for (bh.decInsert(src, 0); !bh.empty(); ) {
        int cur = bh.extract_min();  
        if (cur == dest) return dist[cur];
        vis[cur] = true;
        for (int ee = first[cur]; ee != -1; ee = next[ee]) {
            relax(v[ee], w[ee] + dist[cur]);
        }
    }
    return 0;
}

void add_edge(int ee, int x, int y, int ww)
{
    next[ee] = first[x]; 
    first[x] = ee;
    w[ee] = ww;
    v[ee] = y;
}

void init()
{
    scanf("%d%d", &N, &M);
    n = N*M+2;  --N, --M;
    memset(first, -1, sizeof(first[0])*n);
    int eid = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0, x; j < M; ++j) {
            scanf("%d", &x);
            int Idx = i*M+j+1; 
            int a = Idx<=M ? n-1:(Idx-M)*2-1, b = Idx>N*M ? 0:2*Idx;
            add_edge(eid++, a, b, x);
            add_edge(eid++, b, a, x);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0, x; j <= M; ++j) {
            scanf("%d", &x);
            int Idx = i*M+j+1;
            int a = j==0 ? 0:(Idx-1)*2, b = j==M ? n-1:Idx*2-1;
            add_edge(eid++, a, b, x);
            add_edge(eid++, b, a, x); 
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0, x; j < M; ++j) {
            scanf("%d", &x);
            int Idx = i*M+j+1;
            int a = Idx*2-1, b = 2*Idx;
            add_edge(eid++, a, b, x);
            add_edge(eid++, b, a, x);
        }
    }
    m = eid;
}

int main()
{
    freopen("data.in", "r", stdin);
    init();
    printf("%d\n", dijkstra(0,n-1));
    return 0;
}

