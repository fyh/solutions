# include <cstdio>

int main()
{
    int x, y;
    while (scanf("%d%d", &x, &y)!=EOF) {
        printf("%d/%d = %d.", x, y, x/y);
        int f[5005]={};
        int ans[5005];
        int n = 0;
        for (n = 1; ; ++n) {
            ans[n-1] = x/y;
            x%=y;
            if (f[x]) {
                for (int i = 1; i < f[x]; ++i) printf("%d", ans[i]);
                int c = n-f[x];
                printf("(");
                for (int i = 0; i < (c<=50?c:50); ++i) printf("%d", ans[f[x]+i]);
                printf("%s)\n", c<=50?"":"...");
                printf("   %d = number of digits in repeating cycle\n\n", c);
                break;
            }
            f[x] = n;
            x*=10;
        }
    }
    return 0;
}


/*#include <stdio.h>

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    printf("%d/%d = %d.", n, m, n / m);
    int len, ans[3333] = {}, rec[3333] = {};
    for (len = 1; ; len++) {
      ans[len - 1] = n / m;
      n = n % m;
      if (rec[n]) {
        int i;
        for (i = 1; i < rec[n]; i++) {
          printf("%d", ans[i]);
        }
        printf("(");
        int cycle = len - rec[n];
        for (i = 0; i < (cycle <= 50 ? cycle : 50); i++) {
          printf("%d", ans[rec[n] + i]);
        }
        printf("%s)\n", cycle <= 50 ? "" : "...");
        printf("   %d = number of digits in repeating cycle\n\n", cycle);
        break;
      }
      rec[n] = len;
      n = n * 10;
    }
  }
  return 0;
}
*/
