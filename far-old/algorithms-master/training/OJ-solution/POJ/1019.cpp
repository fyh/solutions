# include <stdio.h>
const int maxn = 32000;
const int INF = 0x7FFFFFFF;

int n;
long long int s[maxn];
long long int f[maxn];
int d[maxn];
int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int calDigit(int x)
{
    for (int i = 0; i < 8; ++i) {
        if (pow10[i] > x) {
            return i;
        }
    }
}
int bs(long long int *v, int k)
{
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (v[mid] >= k) hi = mid;
        else lo = mid+1;
    }
    return lo;
}
int getDigit(int x, int m)
{
    int c = 1;
    while (x>0 && c<m) ++c, x/=10;
    return x%10;
}
int main()
{
    s[0] = 0;
    f[0] = 0;
    for (int i = 1; i < maxn; ++i) {
        d[i] = calDigit(i);
        s[i] = s[i-1] + d[i];
        f[i] = f[i-1] + s[i];
        if (f[n=i] >= INF) break;
    }
    int T;
    scanf("%d", &T);
    for (int ica = 0; ica < T; ++ica) {
        int x; scanf("%d", &x);
        int k = bs(f, x); f[k] >= x;
        if (x == f[k]) printf("%d", k%10);
        else {
            x -= f[k-1];
            int j = bs(s, x); s[j] >= x;
            if (x == s[j]) printf("%d", j%10);
            else printf("%d", getDigit(j, d[j]+1-x+s[j-1]));
        }
        printf("\n");
    }

    return 0;
}
