// 20:00
# include <math.h>
# include <stdio.h>
int main()
{
    float x, y;
    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        scanf("%f%f", &x, &y);
        x = (x*x+y*y) * atan(1.0)*2.0;
        int ans = floor( x/50.0 ) + 1;
        printf("Property %d: This property will begin eroding in year %d.\n", ica, ans);
    }
    printf("END OF OUTPUT.");

    return 0;
}
