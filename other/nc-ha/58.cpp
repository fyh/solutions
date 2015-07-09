# include <stdio.h>

int n;
int h[55];

int main()
{
    while (~scanf("%d", &n)) {
        int s = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &h[i]);
            s += h[i];
        }
        int a = s / n;
        int t = 0;
        for (int i = 0; i < n; ++i) {
            if (h[i] > a) t += h[i] - a;
        }
        printf("%d\n", t);
    }
    return 0;
}
