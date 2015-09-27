/*
Accepted	15864K	1594MS	C++	1229B	2014-10-15 23:34:30
*/

// 最大全1子矩阵
// O(n^2) 
// 单调队列
# include <stdio.h>
# include <string.h>
# include <algorithm>

const int maxn = 2005;

int m, n;
int a[maxn][maxn];

int x[maxn], y[maxn];
int h[maxn], front, rear;

int cal(int *v)
{
    front = rear = 0;
    for (int i = 1; i <= n; ++i) {
        while (front < rear && v[i]<v[ h[rear-1] ]) y[ h[--rear] ] = i;
        h[rear++] = i;
    }
    for (int i = front; i < rear; ++i) y[ h[i] ] = n+1;
    front = rear = 0;
    for (int i = n; i >= 1; --i) {
        while (front < rear && v[i] < v[ h[rear-1] ]) x[ h[--rear] ] = i;
        h[rear++] = i;
    }
    for (int i = front; i < rear; ++i) x[ h[i] ] = 0;
    int ret = 0;
    for (int i = 1; i <= n; ++i) ret = std::max( ret, v[i]*(y[i]-x[i]-1) );
    return ret;
}

int main()
{
    int ans;
    memset(a[0], 0, sizeof(a[0]));
    while (scanf("%d%d", &m, &n) != EOF) {
        ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &a[i][j]);
                a[i][j] = (!a[i][j] ? 0:a[i-1][j] + 1);
            }
            ans = std::max( ans, cal(a[i]) );
        }
        printf("%d\n", ans);
    }

    return 0;
}

