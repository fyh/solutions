# include <cstring>
# include <cstdio>
# include <cstdlib>
# include <cmath>
char s[55];

/*
int main()
{
    ull M, E, b;
    double a, A, tmp, diff;
    while (scanf("%s", s), strcmp(s, "0e0"))
    {
        *strchr(s, 'e') = 32;
        sscanf(s, "%lf%llu", &a, &b);
        For(M, 10)
        {
            tmp = log2(1 - 1.0 / (1 << (M + 1)));
            E = (ull)round(log2(A - tmp + 1));
            if (fabs(A - ((1 << E) - 1) - tmp) < eps) break;
        }
        printf("%llu %llu\n", M, E);
    }
    return 0;
}

*/

int main()
{
    while (scanf("%s", s), strcmp(s, "0e0"))
    {
        int t = strchr(s, 'e') - s;
        s[t] = ' ';

        double x;
        int y;
        sscanf(s, "%lf%d", &x, &y);
        double A = log2(x) + y * log2(10);
        int E = round(log2(floor(A)+1.9)), M;
        A -= ((1<<E)-1);
        for (M = 1; M <= 10; ++M) {
            if (fabs(log2(1-1.0/(1<<M))-A) <= 1e-6) break;
        }

        printf("%d %d\n", M-1, E);
    }
    return 0;
}



/*
int main()
{
    while (scanf("%s", s), strcmp(s, "0e0"))
    {
        int t = strchr(s, 'e') - s;
        s[t] = ' ';

        double x;
        unsigned long long int y;
        sscanf(s, "%lf %llu", &x, &y);
        //double x = atof(s);
        //int y = atoi(s+t+1);

        int E, M;
        double tt;
        for (E = 1; E <= 35; ++E)
        {
            tt = ((1<<E) - 1) * log10(2.0);
            unsigned long long int ttt = (unsigned long long int )tt;
            if ( ttt == y ) break;
        }
        for (M = 1; M <= 15; ++M)
        {
            double t = 1;
            for (int i = 0; i < M; ++i) t*=0.5;
            double ll = log10(1-t) + (tt-y);
            if (fabs(ll-log10(x)) <= 1e-9)
            {
                break;
            }
        }
        printf("%d %d\n", M-1, E);
    }
    return 0;
}
*/
