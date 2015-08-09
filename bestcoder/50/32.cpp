# include <iostream>
using namespace std;

typedef long long int lli;

const int maxn = 65;

lli f[maxn];
lli s[maxn];

int n;

int main()
{
    for (int i = 1; i < maxn; ++i) {
        f[i] = 1;
        if (i>2) f[i] += s[i-3];
        s[i] = s[i-1] + f[i];
    }

    while (cin >> n) cout << s[n] << endl;

    return 0;
}
