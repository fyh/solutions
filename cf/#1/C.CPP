# include <math.h>
# include <stdio.h>

# define PI 3.14159265358979323846

double x[3], y[3];
void read(void) {
    for (int i = 0; i < 3; ++i) {
        scanf("%lf%lf", &x[i], &y[i]);
    }
}

# define SQ(X) ((X)*(X))
double a[2], b[2], c[2];
void build(void) {
    a[0] = 2.0*(x[1]-x[0]);
    a[1] = 2.0*(x[2]-x[0]);
    b[0] = 2.0*(y[1]-y[0]);
    b[1] = 2.0*(y[2]-y[0]);
    c[0] = (SQ(x[1])+SQ(y[1])-SQ(x[0])-SQ(y[0]));
    c[1] = (SQ(x[2])+SQ(y[2])-SQ(x[0])-SQ(y[0]));
}

# define M(A, B) ( (A[0]*B[1]) - (A[1]*B[0]) )
double mx0, my0;
void center(void) {
    mx0 = M(c,b) / M(a,b);
    my0 = M(a,c) / M(a,b);
}

# define AN(I) (atan2(y[I]-my0, x[I]-mx0))
double p, q;
void calc_ang(void) {
    p = AN(0)-AN(1);
    q = AN(2)-AN(1);
}

# define ZERO (1e-4)
double fgcd(double A, double B) {
    if (fabs(B) <= ZERO) return A;
    return fgcd(B, fmod(A, B));
}

# define D2(I) (SQ(x[I]-mx0) + SQ(y[I]-my0))
void solve(void) {
    double alpha = fgcd(2*PI, fgcd(p, q));
    printf("%lf\n", sin(alpha) * D2(0) * PI / alpha);
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    //testin;

    read();
    build();
    center();
    calc_ang();
    solve();

    return 0;
}
