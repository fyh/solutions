# include <stdio.h>
# include <math.h>

char str[1000005];
int b;

int st;

typedef long long int lli;

lli get(int base, int p) {
    lli ret = 1;
    for (int i = 0; i < p; ++i) ret = ret * base;
    return ret;
}

int main()
{
    while ((~scanf("%s%d", str, &b)) && b) {
        int up = log(1000005)/log(b) + 5;
        // printf("%d\n", up);

        for (st = 0; str[st] != '.'; ++st) ;
        int m = 0;
        for (int i = st+1; i-st<up && str[i]; ++i) {
            if (str[i] != '0') m = i-st;
        }
        lli num = 0;
        for (int i = st+1; i-st<up && str[i]; ++i)
        {
            num += (str[i]-'0') * get(b, m-(i-st));
        }
        double ans = 1.0*num / get(b, m);
        printf("%.6f\n", ans);
    }

    return 0;
}
