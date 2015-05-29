# include <bits/stdc++.h>

# define rep(I, N) for(int I = 0; I < N; ++I)

const int maxn = 5e6+5;
int p[maxn];
int f[maxn*2];
char s[maxn];
char t[maxn*2];
int n;
void prep()
{
    t[0] = '$';
    n = 1;
    for (int i = 0; s[i]; ++i) {
        t[n++] = '#';
        t[n++] = s[i];
    }
    t[n++] = '#';
    t[n] = 0;
    int mx = 0, mi;
    for (int i = 0; t[i]; ++i) {
        if (mx > i) f[i] = std::min(f[2*mi-i], mx-i);
        else f[i] = 1;
        for (; t[i-f[i]] == t[i+f[i]]; ++f[i]) ;
        if (i+f[i] > mx) {mx = i + f[i]; mi = i;}
    }
}
bool isP(int x, int y)
{
    return f[x+y+2] == y-x+2;
}
int main()
{
    scanf("%s", s);
    prep();
    long long int ans = 0;
    for (int i = 0; s[i]; ++i) {
        if (isP(0, i)) {
            p[i] = p[std::max(0,(i+1)/2-1)] + 1;
        }
        ans += p[i];
    }
    printf("%I64d\n", ans);
    return 0;
}
