# include <stdio.h>
# include <string.h>
char s[100005], t[100005];
int main()
{
    while (true) {
        scanf("%s%s", s, t);
        if (strcmp(s, "0") ==0 && strcmp(t, "0") == 0) {
            break;
        }
        for (int i = 0; t[i]; ++i) t[i] = 25-(t[i]-'A') + 'A';
        int n = strlen(s), m = strlen(t);
        int i = 0, j = 0;
        for (;i < n && j < m; ) {
            if (s[i] == t[j]) {
                ++i, ++j;
            } else {
                ++i;
            }
        }
        if (j < m) puts("No");
        else puts("Yes");
    }

    return 0;
}
