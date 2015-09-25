/*
Accepted	4048K	6672MS	C++	999B
*/

// 单调队列
# include <stdio.h>

const int maxn = 1000005;

int n, k;
int x[maxn];
int a[maxn];
int front, rear;

int main()
{
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
        front = 0, rear = 0;
        for (int i = 0; i < n; ++i) {
            while (rear > front && x[i] < x[ a[rear-1] ]) --rear;
            a[rear++] = i;
            while (front < rear && i-a[front]+1 > k) ++front;
            if (i+1>=k) {
                printf("%d", x[a[front]]);
                printf(i+1<n ? " ":"\n");
            }
        }
        front = 0, rear = 0;
        for (int i = 0; i < n; ++i) {
            while (rear > front && x[i] > x[ a[rear-1] ]) --rear;
            a[rear++] = i;
            while (front < rear && i-a[front]+1 > k) ++front;
            if (i+1>=k) {
                printf("%d", x[a[front]]);
                printf(i+1<n ? " ":"\n");
            }
        }
    }

    return 0;
}

