# include <bits/stdc++.h>

const int maxn = 105;

int n;
char str[55];
int ti[maxn];

int get() {
    gets(str);
    int hour = (str[1]-'0')*10 + (str[2]-'0');
    int min = (str[4]-'0')*10 + (str[5]-'0');
    int t = (str[7]=='a' ? 0:1);
    if (hour == 12) hour = 0;
    return (hour+t*12)*60 + min;
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    // testin;
    scanf("%d", &n); gets(str);
    for (int i = 0; i < n; ++i) {
        ti[i] = get();// printf("%d\n", ti[i]);
    }
    int ans = 0;
    int pre = 98765;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (ti[i] > pre) cnt = 1;
        else if (ti[i] == pre && cnt < 10) ++cnt;
        else ++ans, cnt = 1;
        pre = ti[i];
    }
    printf("%d\n", ans);

    return 0;
}
