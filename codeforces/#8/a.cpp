# include <bits/stdc++.h>

# define testin freopen("in.txt", "r", stdin)

const int maxn = 1e5+5;
const int maxm = 1e2+5;

char s[maxn];
char rs[maxn];
char t1[maxm];
char t2[maxm];

void read() {
    scanf("%s%s%s", s, t1, t2);
    int n = strlen(s);
    for (int i = 0; s[i]; ++i) {
        rs[i] = s[n-1-i];
    }
}

bool judge(char *str, char *a, char *b) {
    char *x = strstr(str, a);
    if (!x) return false;
    char *y = strstr(x+strlen(a), b);
    if (!y) return false;
    return true;
}

int main()
{
    // testin;

    read();
    bool a = judge(s, t1, t2);
    bool b = judge(rs, t1, t2);
    if (!a && !b) puts("fantasy");
    else if (a && b) puts("both");
    else if (a) puts("forward");
    else puts("backward");

    return 0;
}
