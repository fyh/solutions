# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int a, b, c;

int rm(int x) {
    int ret = 0;
    int p = 1;
    while (x > 0) {
        if (x%10!=0) ret = ret + x%10 * p, p*=10;
        x /= 10;
    }
    return ret;
}

int main()
{
    cin >> a >> b; c = a + b;

    if (rm(a) + rm(b) == rm(c)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
