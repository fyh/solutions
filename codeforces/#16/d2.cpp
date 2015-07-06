# include <bits/stdc++.h>

const int maxn = 105;

int n;
char str[55];
int ti[maxn];

int get() {
    gets(str);// puts(str);
    int hour = (str[1]-'0')*10 + (str[2]-'0');
    int min = (str[4]-'0')*10 + (str[5]-'0');
    int t = str[7]=='a' ? 0:1;
    if (hour == 12) hour = 0;
    return (hour+t*12)*60 + min;
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
   // testin;
    scanf("%d", &n); gets(str);
    for (int i = 0; i < n; ++i) {
        ti[i] = get(); //printf("%d\n", ti[i]);
    }
    int ans = 1;
    int pre = -1;
    for (int i = 0; i < n; ++i) {
        if (ti[i] < pre) ++ans;
        pre = ti[i];
    }

    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (ti[i]==ti[i-1]) {
            ++cnt;
        } else {
            cnt = 1;
        }
        if (cnt > 10) {
            ++ans;
            cnt = 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
