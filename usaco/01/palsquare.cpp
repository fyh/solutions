/*
ID: yajunwf1
LANG: C++11
TASK: palsquare
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

int B;

void get(char *s, int x, int base) {
    int i = 0;
    while (x > 0) {
        int t = x%base;
        s[i++] = (t<10 ? t+'0':t-10+'A');
        x/=base;
        s[i] = 0;
    }
    reverse(s, s+i);
}

bool chk(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

void doit(int x) {
    int t = x * x;
    char s[35];
    get(s, t, B);
    if (chk(s)) {
        char sx[35];
        get(sx, x, B);
        cout << sx << ' ' << s << endl;
    }
}

int main()
{
    rdio(palsquare);

    cin >> B;
    for (int i = 1; i <= 300; ++i) {
        doit(i);
    }

    return 0;
}
