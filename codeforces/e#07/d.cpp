# include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+5;

int n;
int a[maxn*2];
int b[maxn*2];
int c[maxn*2];

int main()
{
    cin >> n;
    int ka = 1, kb = 1;

    b[maxn] = n;

    for (int i = n-1; i > 0; --i) {
        if ((n-i)%2) {
            a[maxn+ka] = a[maxn-ka] = i;
            ++ka;
        } else {
            b[maxn+kb] = b[maxn-kb] = i;
            ++kb;
        }
    }
    for (int i = 0; i < 2*maxn; ++i) {
        if (a[i]) cout << a[i] << ' ';
    }
    for (int i = 0; i < 2*maxn; ++i) {
        if (b[i]) cout << b[i] << ' ';
    }
    cout << n << endl;

    return 0;
}
