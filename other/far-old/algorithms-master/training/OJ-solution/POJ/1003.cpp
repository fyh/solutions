// 19:56
# include <stdio.h>

const int maxn = 1005;
double f[maxn];

int n;
double x;

int bs(double v)
{
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = lo + (hi-lo)/2;
        if (f[mid] < v) {
            lo = mid+1;
        } else hi = mid;
    }
    return lo;
}

int main()
{
    f[0] = 0;
    for (n = 1; n < maxn; ++n) {
        f[n] = f[n-1] + 1.0/(n+1);
        if (f[n] >= 5.20) break;
    }
    while (scanf("%lf", &x), x!=0.00) {
        printf("%d card(s)\n", bs(x));
    }

    return 0;
}
