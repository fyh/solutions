# include <stdio.h>
int main()
{
    double ans, x;
    ans = 0;
    for (int i = 0; i < 12; ++i) {
        scanf("%f", &x); ans += x;
    }
    printf("$%.2f", ans/12);

    return 0;
}
