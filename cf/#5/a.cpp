# include <stdio.h>
# include <string.h>
char cc[105];
int cnt = 0;
int main()
{
    // freopen("in.txt", "r", stdin);
    int ans = 0;
    while (gets(cc) != NULL) {
        if (cc[0] == '+') {
            ++cnt;
        } else if (cc[0] == '-') {
            --cnt;
        } else {
            int n = strlen(cc);
            for (int i = 0; cc[i]; ++i) {
                if (cc[i] == ':') {
                    ans += cnt * (n-1-i);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

