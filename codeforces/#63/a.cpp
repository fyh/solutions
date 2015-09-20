# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;
int x, y, z;

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        x += a, y += b, z += c;
    }

    if (!x && !y && !z) cout << "YES";
    else cout << "NO";
    cout << endl;

    return 0;
}
