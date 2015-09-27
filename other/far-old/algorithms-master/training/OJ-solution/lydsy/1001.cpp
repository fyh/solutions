/**************************************************************
    Problem: 1001
    User: fyh
    Language: C++
    Result: Accepted
    Time:900 ms
    Memory:161588 kb
****************************************************************/

# include <cstdio>
# include <cstring>

const int maxn = 1005;
const int maxv = 3*maxn*maxn;
const int maxe = 5*maxn*maxn;
const int INF = 0x7FFFFFFF;

int N, M;
int n, m;
int w[maxe], id[maxe];

int src, dest;
int srcLink[2*maxn];
int link[maxv][5];

int d[maxv];
int h[maxv * 4], hh;
bool vis[maxv];

void add_link(int u, int eid)
{
  if (u == dest) return ;
  if (u == src) {
    srcLink[ ++srcLink[0] ] = eid;
  } else {
    link[u][ ++link[u][0] ] = eid;
  }
}
void add_edge(int x, int y)
{
  add_link(x, m);
  add_link(y, m);
  id[m++] = x ^ y;
}

void init(void)
{
  m = 0;
  scanf("%d%d", &N, &M); --N, --M;
  src = 0;
  dest = 2*N*M + 1;
  n = dest + 1;
  srcLink[0] = 0;
  for (int i = 0; i < n; ++i) link[i][0] = 0;
  for (int i = 0; i < N+1; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%d", &w[m]);
      int cell = i*M+j+1; /// starts from 1
      int x = 2*(cell-M) - 1;
      int y = 2*cell;
      if (x < src) x = src;
      if (y > dest) y = dest;
      add_edge(x, y);
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M+1; ++j) {
      scanf("%d", &w[m]);
      int cell = i*M+j+1;
      int x = 2*(cell-1);
      int y = 2*cell-1;
      if (j == 0) x = dest;
      if (j == M) y = src;
      add_edge(x, y);
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%d", &w[m]);
      int cell = i*M+j+1;
      int x = 2*cell-1;
      int y = 2*cell;
      add_edge(x, y);
    }
  }
}

void init_bheap(void)
{
  for (hh = 0; (1<<hh) < n; ++hh);
  for (int i = 0; i < (1<<hh); ++i) d[i] = INF;
  d[0] = 0;
  memset(h, 0, sizeof(h[0]*((1<<hh)-1)));
  for (int i = 0; i < (1<<hh); ++i) h[(1<<hh) + i] = i;
}

void modify(int x, int k)
{
  d[x] = k;
  int t = x + (1<<hh);
  while (t > 1) {
    h[t>>1] = d[ h[t] ] < d[ h[t^1] ]  ?  h[t] : h[t^1];
    t >>= 1;
  }
}

int extract_min(void)
{
  int ret = h[1];
  vis[ret] = true;
  return ret;
}

int dijkstra(void)
{
  if (!N||!M) {
    int ans = INF;
    for (int i = 0; i < m; ++i) if (ans > w[i]) ans = w[i];
    return ans;
  }
  init_bheap();
  memset(vis, 0, sizeof(vis[0])*n);
  for (int i = 0; i < n-1; ++i) {
    int x = extract_min();
    if (x == dest) return d[x];
    else {
      int dd = d[x];
      modify(x, INF);
      int cnt = x==src ? srcLink[0]:link[x][0];
      int * p = x==src ? srcLink : link[x];
      for (int j = 1; j <= cnt; ++j) {
        int e = p[j];
        int v = id[e] ^ x;
        if (!vis[v] && d[v]>w[e]+dd) modify(v, w[e]+dd);
      }
    }
  }
  return INF;
}
int main()
{
  init();
  int ans = dijkstra();
  printf("%d\n", ans);

  return 0;
}

