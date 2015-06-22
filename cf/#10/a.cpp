# include <bits/stdc++.h>

int n, P1, P2, P3, T1, T2;

void read() {
    scanf("%d%d%d%d%d%d", &n, &P1, &P2, &P3, &T1, &T2);
}

void solve() {
    int cons = 0;
    int pre = 0;
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        int d = l - pre;
        if (!i) d = 0;
        pre = r;
        if (d > T1) {
            cons += P1 * T1;
            d -= T1;
            if (d > T2) {
                cons += P3 * (d-T2) + P2 * T2;
            } else {
                cons += P2 * d;
            }
        } else {
            cons += P1 * d;
        }
        cons += (r - l) * P1;
    }
    printf("%d\n", cons);
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    //testin;

    read();
    solve();

    return 0;
}
