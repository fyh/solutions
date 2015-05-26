# include <stdio.h>

const int maxn = 1e5+5;
int t[maxn];
int n;
int cb, ca;
int nb, na;

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
    int i = 0, j = n-1;
    while (i <= j) {
        if (ca <= cb) {
            ++na;
            ca += t[i];
            ++i;
        } else {
            ++nb;
            cb += t[j];
            --j;
        }
    }
    printf("%d %d\n", na, nb);
    return 0;
}

