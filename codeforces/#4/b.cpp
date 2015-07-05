# include <stdio.h>
# include <algorithm>
const int maxn = 35;
int d, st;
int lo[maxn], hi[maxn];
int main()
{
    int lb = 0, hb = 0;
    scanf("%d%d", &d, &st);
    for (int i = 0; i < d; ++i) {
        scanf("%d%d", &lo[i], &hi[i]);
        lb += lo[i], hb += hi[i];
    }
    if (lb<=st && st<=hb) {
        puts("YES");
        int r = st-lb;
        for (int i = 0; i < d; ++i) {
            int t = 0;
            if (r>0) {
                t = hi[i] - lo[i];
                t = std::min(t, r);
                r -= t;
            }
            printf("%d ", lo[i]+t);
        }
        puts("");
    } else puts("NO");
    return 0;
}
