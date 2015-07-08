# include <string.h>
# include <stdio.h>

const int maxn = 10005;

char s[maxn], t[maxn];

bool ok() {
    bool a[256];
    bool b[256];
    memset(a, false, sizeof(a));
    memset(b, false, sizeof(b));
    for (int i = 0; s[i]; ++i) a[ s[i] ] = true;
    for (int i = 0; t[i]; ++i) b[ t[i] ] = true;
    for (int i = 0; i < 256; ++i) {
        if (!a[i] && b[i]) return false;
    }
    return true;
}

int main()
{
    while (~scanf("%s%s", s, t)) {
        int n = strlen(s);
        int m = strlen(t);
        if (n <= m || !ok()) {
            puts("No");
        } else {
            puts("Yes");
        }
    }

    return 0;
}
