# include <stdio.h>

const int maxn = 5000005;
int isp[maxn];
int sum[maxn];

int main()
{
    for (int i = 2; i < maxn; ++i) {
        if (!isp[i]) {
            isp[i] = 1;
            for (int j = 2; j*i < maxn; ++j) {
                isp[j*i] = 1 + isp[j];
            }
        }
    }

    for (int i = 1; i < maxn; ++i) sum[i] += sum[i-1] + isp[i];

    int t;
    scanf("%d", &t);
    for(int i = 0; i <t; ++i) {
        int a , b;
        scanf("%d%d", &a, &b);
        printf("%d\n", sum[a]-sum[b]);
    }

    return 0;
}

