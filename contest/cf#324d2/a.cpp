# include <bits/stdc++.h>
using namespace std;

int n, t;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> t;

    if (n==1 && t==10) puts("-1");
    else {
        int r = 0;
        if (n > 1) {
            putchar('1');
            r = 10 % t;
            for (int i = 2; i < n; ++i) {
                putchar('0');
                r = r*10 % t;
            }
        }
        if (t == 10) putchar('0');
        else putchar(t-r+'0');
    }

    return 0;
}
