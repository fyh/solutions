# include <cstdio>

const int maxn = 20;

int n, c;
int a[maxn];
int l[maxn], r[maxn];

void init() {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        l[i] = (i+n-1)%n, r[i] = (i+1)%n;
    }
}

int getNext(int cur, int d) {
    return d==1 ? r[cur]:l[cur];
}
void rm(int x) {
    l[ r[x] ] = l[x];
    r[ l[x] ] = r[x];
}
void solve() {
    int d = 1;
    int ca = 0;
    int cur = 0;
    while (true) {
        if (a[cur] <= c) {
            if (getNext(cur, d) == cur) {
                printf("%d\n", cur+1);
                return ;
            }
            rm(cur), d = -d;
        } else a[cur] -= c;
        ++ca;
        if (ca >= n+5) {
            printf("%d\n", cur+1);
            return ;
        }
        cur = getNext(cur, d);
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--)  {
        init();
        solve();
    }

    return 0;
}
