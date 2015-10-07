/*
ID: yajunwf1
LANG: C++11
TASK: dualpal
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

void getb(char *s, int x, int base) {
    int i = 0;
    while (x > 0) {
        s[i++] = x%base+'0';
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

int get(int x) {
    int r = 0;
    for (int i = 2; i <= 10; ++i) {
        char s[35];
        getb(s, x, i);
        if (chk(s)) ++r;
    }
    return r;
}

bool doit(int x) {
    int c = get(x);
    if (c > 1) {
        cout << x << endl;
        return true;
    }
    return false;
}

int main()
{
    rdio(dualpal);

    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        while (!doit(++s)) ;
    }

    return 0;
}
