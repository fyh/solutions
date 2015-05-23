# include <stdio.h>

int main()
{
    int k,n,w;
    scanf("%d%d%d", &k, &n, &w);
     long long int ww = k*(w*(w+1)/2);
   /* long long int ww = w;
    ww = ww*(ww+1)/2;
    ww *= k;
    */
    if (ww <= n) puts("0");
    else printf("%lld\n", ww-n);
    return 0;
}
