# include <stdio.h>
# include <algorithm>

int p, q, r;

int get(int x) {
    int ret = x % 10;
    while (x > 0) {
        ret = std::max(ret, x%10);
        x/=10;
    }
    return ret;
}

int gg(int x, int b) {
    int ret = 0, t = 1;
    for (int i = 0; x > 0; ++i) {
        ret = ret + (x % 10) * t;
        x /= 10;
        t *= b;
    }
    return ret;
}

void solve(void) {
    int from = std::max(get(p), std::max(get(q), get(r)));
    for (int i = std::max(2,from+1); i < 17; ++i) {
        int pp = gg(p, i);
        int qq = gg(q, i);
        int rr = gg(r, i);
        if (pp * qq == rr) {
            printf("%d\n", i);
            return ;
        }
    }
    printf("0\n");
}

int main()
{
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &p, &q, &r);
        solve();
    }

    return 0;
}
