/*
  2014-10-15 16:57:04 	Txd0u	Largest Rectangle in a Histogram	accepted     0.43 s 	4.1M 	C++ 4.3.2
*/

// 单调队列
// 维护两个单调递增队列

# include <stdio.h>

const int maxn = 100005;

int n;
int a[maxn];
int x[maxn], y[maxn];
int h[maxn], front, rear;

typedef long long int lli;

lli Max( const lli &x, const lli &y ) { return x > y ? x : y; }

int main()
{
    while (1) {
        scanf("%d", &n); if (!n) break;
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        lli ans = 0;
        front = 0, rear = 0;
        for (int i = 0; i < n; ++i) {
            while (front < rear && a[i] < a[ h[rear-1] ]) {
                y[ h[rear-1] ] = i;
                --rear;
            }
            h[rear++] = i;
        }
        while (front < rear) y[ h[--rear] ] = n;
        front = rear = 0;
        for (int i = n-1; i >= 0; --i) {
            while (front < rear && a[i] < a[ h[rear-1] ]) {
                x[ h[rear-1] ] = i;
                --rear;
            }
            h[rear++] = i;
        }
        while (front < rear) x[ h[--rear] ] = -1;
        for (int i = 0; i < n; ++i) ans = Max( (lli)a[i]*(y[i]-x[i]-1), ans );
        printf("%lld\n", ans);
    }

    return 0;
}

