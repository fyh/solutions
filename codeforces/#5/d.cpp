# include <stdio.h>
# include <math.h>

int a, v, l, d, w;

double cal(int s, int b)
{
    if (2*a*s >= (v*v-b*b)) {
        return 1.0*(v-b)/a + (s-0.5*(v*v-b*b)/a)/v;
    } else return (1.0*sqrt(2*a*s+b*b)-b) / a;
}

int main()
{
    double ans = 0.0;
    scanf("%d%d%d%d%d", &a, &v, &l, &d, &w);
    if (2*a*d <= w*w || v <= w) {
        ans = cal(l, 0);
    } else {
        if (2*a*d+w*w<=2*v*v) {
            ans = (2*sqrt(a*d+0.5*w*w)-w)/a;
        } else {
            ans = 1.0*(v+v-w)/a + (2*a*d+w*w-2*v*v)/(2.0*a*v);
        }
        ans += cal(l-d, w);
    }
    printf("%.6lf\n", ans);

    return 0;
}
