# include <bits/stdc++.h>
# define testin freopen("in.txt", "r", stdin)

using namespace std;

const int maxn = 2e5+5;

int n;
char str[maxn];
char s[maxn];
int top = 0;

int main()
{
    testin;
    scanf("%d%s", &n, str);
    int ans = n;
    for(int i = 0; str[i]; ++i) {
        s[top++] = str[i];
        if (top >= 2 && s[top-1]+s[top-2] == '0'+'1') {
            top -= 2;
            ans -= 2;
        }
    }
    printf("%d\n", ans);

    return 0;
}
