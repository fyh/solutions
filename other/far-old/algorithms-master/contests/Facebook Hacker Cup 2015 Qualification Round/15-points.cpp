# include <algorithm>
# include <stdio.h>

# define setin  freopen("cooking_the_books.txt", "r", stdin);
# define setout freopen("out.txt", "w", stdout);

int T;
int x;
int a[15], n;
int pow10[10];

int main()
{
    setin;
    setout;
    pow10[0] = 1;
    for (int i = 1; i < 10; ++i) {
        pow10[i] = 10 * pow10[i-1];
    }
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        scanf("%d", &x);
        n = 0;
        for (int t = x; t>0 ;t/=10) {
            a[n++] = t%10;
        }
        int mx = x, mm = x;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (a[i]==0 && j+1==n) continue;
                mx = std::max(mx, x+(a[i]-a[j])*(pow10[j]-pow10[i]) );
                mm = std::min(mm, x+(a[i]-a[j])*(pow10[j]-pow10[i]) );
            }
        }
        printf("Case #%d: %d %d\n", ica, mm, mx);
    }

    return 0;
}
