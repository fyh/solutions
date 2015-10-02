# include <stdio.h>
# include <math.h>

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        int k; scanf("%d", &k);
        int n = sqrt(k);
        for (; (n-1)*(n-2) <= 2*k ; ++n) ;
        if (n < 1) n = 1;
        printf("%d\n", n);
        int p = n, q = 1;
        bool first = true;
        while (p >= q) {
            if (first) first = false;
            else putchar(' ');
            if (k >= p-q) {
                printf("%d", p);
                k -= p-q;
                --p;
            } else {
                printf("%d", q);
                ++q;
            }
        }
        puts("");
    }
}
