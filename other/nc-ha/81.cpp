# include <stdio.h>

int m, d;

bool ok[105];

int get(int x) {
    int ret = 0;
    for (int i = x; i < 62; ++i) {
        if (ok[i]) ++ret;
    }
    return ret;
}

int main()
{
    int c = 0;
    int sum = 0;
    ok[0] = true;
    for (int i = 2; ; ++i) {
        sum += i;
        if (sum > 105) break;
        ok[sum] = true;
    }

    while (~scanf("%d/%d", &m, &d)) {
        if (!m && !d) break;
        int f = 0;
        if (m == 8) f = 30 + d;
        else f = d - 1;
        printf("%d\n", get(f));
    }

    return 0;
}
