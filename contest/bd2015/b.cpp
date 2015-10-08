# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <map>
using namespace std;
typedef long long int lli;

const int maxn = 10005;

char a[maxn];
char b[maxn];

map<int, int> M;

int main()
{
    scanf("%s%s", a, b);

    for (int i = 0; a[i]; ++i) {
        int t = a[i];
        if (t >= 128) {
            t = (t<<8) + (int)a[i+1];
            ++ M[t];
            ++i;
        } else {
            ++ M[t];
        }
    }

    bool ok = true;

    if (strlen(b) > strlen(a)) ok = false;

    for (int i = 0; b[i]; ++i) {
        int t = b[i];
        if (t >= 128) {
            t = (t<<8) + (int)b[i+1];
            ++i;
        }
        if (M.count(t) <= 0 || M[t] <= 0) {
            ok = false;
            break;
        } else {
            --M[t];
        }
    }

    puts(ok ? "1":"0");

    return 0;
}
