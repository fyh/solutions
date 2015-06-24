# include <bits/stdc++.h>
using namespace std;

# define testin freopen("in.txt", "r", stdin)

typedef long long int lli;

const int maxn = 55;

int n;

int head;
int L[maxn], R[maxn];

int k;
int ck;
int cs[maxn*3];
int sol[maxn*3];

lli ans = 0x7FFFFFFFFFFF;
lli dis[maxn];
lli dis2[maxn][maxn];

lli d1(int c) {
    return 2 * dis[c];
}

lli d2(int x, int y) {
    return dis2[x][y];
}

void del(int x) {
    R[L[x]] = R[x];
    L[R[x]] = L[x];
}

void rec(int x) {
    R[L[x]] = L[R[x]] = x;
}

void pr(void) {
    cout << head;
    for (int i = R[head]; i != head; i = R[i]) {
        cout << "->" << i;
    }
    cout << endl;
}

void dfs(int sum, int cnt) {
    if (cnt >= n) {
        if (sum < ans) {
            ans = sum;
            ck = k;
            for (int i = 0; i < k; ++i) sol[i] = cs[i];
        }
        return ;
    }
    if (sum > ans) return ;
    int cur = R[head];
    if (cur == head) return ;
    // case 1
    if (sum + d1(cur) < ans) {
        cs[k++] = cur;
        cs[k++] = -1;
        del(cur);
        dfs(sum+d1(cur), cnt+1);
        rec(cur);
        k -= 2;
    }
    // case 2
    del(cur);
    cs[k++] = cur;
    for (int t = R[head]; t != head; t = R[t]) {
        if (sum+d2(cur,t) > ans) continue;
        cs[k++] = t;
        cs[k++] = -1;
        del(t);
        dfs(sum+d2(cur,t), cnt+2);
        rec(t);
        k -= 2;
    }
    rec(cur);
    --k;
}

lli sx, sy;
lli x[maxn], y[maxn];

void read() {
    cin >> sx >> sy;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        x[i] -= sx;
        y[i] -= sy;
    }
}

# define SQ(x) ((x) * (x))

void pre() {
    for (int i = 0; i < n; ++i) {
        dis[i] = SQ(x[i]) + SQ(y[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            lli cc = SQ(x[i]-x[j]) + SQ(y[i]-y[j]);
            dis2[i][j] = dis[i] + dis[j] + cc; // min(dis[i] + dis[j] + cc, min(2 * dis[i] + 2 * cc, 2 * dis[j] + 2 * cc));
        }
    }
    head = n;
    for (int i = 0; i <= n; ++i) R[i] = i + 1, L[i] = i-1;
    L[0] = head;
    R[head] = 0;
}

int main()
{
    // testin;

    read();
    pre();
    dfs(0, 0);

    cout << ans << endl << "0";
    for (int i = 0; i < ck; ++i) {
        cout << ' ' << sol[i] + 1;
    }
    cout << endl;

    return 0;
}
