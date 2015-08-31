# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

string a, b;

int main()
{
    cin >> a >> b;
    reverse(b.begin(), b.end());

    if (a == b) cout << "YES";
    else cout << "NO";

    cout << endl;

    return 0;
}
