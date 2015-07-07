# include <stdio.h>

const int maxn = 1e5+5;

bool isp[maxn];
int pt[maxn], pc = 0;
int ans[maxn];

int main()
{
    for (int i = 2; i < maxn; ++i) {
        if (!isp[i]) {
            pt[pc++] = i;
            for (int j = 2; j*i < maxn; ++j) isp[j*i] = true;
        }
    }

    for (int i = 0; i < pc; ++i) {
        for (int j = i+1; j < pc; ++j) if (pt[i]+pt[j] < maxn) {
            ++ans[ pt[i] + pt[j] ];
        }
    }

    int x;
    while ((~scanf("%d", &x)) && x) {
        printf("%d\n", ans[x]);
    }

    return 0;
}
