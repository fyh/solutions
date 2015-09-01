# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;
int c[3];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++c[x%3];
    }

    cout << c[0]/2 + min(c[1], c[2]) << endl;

    return 0;
}
