# include <string.h>
# include <stdio.h>
# include <iostream>

const int maxn = 100005;
typedef long long int lli;
lli sum[4*maxn];
lli lazy[4*maxn];
int N, Q;
void init(void)
{
    scanf("%d%d", &N, &Q);
    memset(sum, 0, sizeof(sum[0])*(4*N));
    memset(lazy, 0, sizeof(lazy[0])*(4*N));
}

void push(int c, int l, int r)
{
    if (lazy[c]) {
        int mid = l + (r-l)/2;
        sum[c<<1] += (mid+1-l)*lazy[c];
        sum[c<<1|1] += (r-mid)*lazy[c];
        lazy[c<<1] += lazy[c];
        lazy[c<<1|1] += lazy[c];
        lazy[c] = 0;
    }
}

void update(int c)
{
    sum[c] = sum[c<<1] + sum[c<<1|1];
}

void add(int c, int l, int r, int x, int y, int d)
{
    if (x<=l && r<=y) {
        sum[c] += d*(r-l+1);
        lazy[c] += d;
    } else {
        push(c, l, r);
        int mid = l + (r-l)/2;
        if (x<=mid) add(c<<1, l, mid, x, y, d);
        if (mid+1<=y) add(c<<1|1, mid+1, r, x, y, d);
        update(c);
    }
}

lli query(int c, int l, int r, int x, int y)
{
    if (x<=l && r<=y) {
        return sum[c];
    } else {
        push(c, l, r);
        lli ret = 0;
        int mid = l + (r-l)/2;
        if (x<=mid) ret += query(c<<1, l, mid, x, y);
        if (mid+1<=y) ret += query(c<<1|1, mid+1, r, x, y);
        return ret;
    }
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    testin;

    init();
    for (int i = 0; i < N; ++i) {
        int x; scanf("%d", &x);
        add(1, 0, N-1, i, i, x);
    }
    for (int i = 0; i < Q; ++i) {
        char ch[5];
        int a, b, c;
        scanf("%s", ch);
        if (ch[0] == 'Q') {
            scanf("%d%d", &a, &b);
            if (a>b) std::swap(a, b);
            printf("%lld\n", query(1, 0, N-1, a-1, b-1));
        } else {
            scanf("%d%d%d", &a, &b, &c);
            if (a>b) std::swap(a, b);
            add(1, 0, N-1, a-1, b-1, c);
        }
    }
    return 0;
}
