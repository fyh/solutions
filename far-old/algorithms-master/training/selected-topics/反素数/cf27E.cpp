# include <stdio.h>

typedef long long int lli;

const lli inf = (lli)0x7FFFFFFFFFFFFFFF;

lli ans;
int p[] = {2,3,5,7,11,13,17,19,23,29,-1};
lli pp[15][64];

void prep() {
    for (int i = 0; p[i] > 0 ; ++i ) {
        pp[i][0] = 1;
        for (int j = 1; j < 64 ;++j) {
            pp[i][j] = pp[i][j-1]*p[i];
        }
    }
}
void dfs(int pt, lli cur, int d, int left)
{
    if (left <= 1) {
        if (ans > cur) ans = cur;
    } else for (int i = 1; i <= pt; ++i) {
        if (left%(i+1) != 0) continue;
        if (ans/cur < pp[d][i]) break;
        dfs(i, cur*pp[d][i], d+1, left/(i+1));
    }
}

int main()
{
    prep();
    int n;
    scanf("%d", &n);
    ans = inf;
    dfs(63, 1, 0, n);
    printf("%lld\n", ans);

    return 0;
}
