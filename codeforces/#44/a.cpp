# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;

int main()
{
    cin >> n;
    int x = sqrt(n * 2);
    cout << (2*n == x*(x+1) ? "YES":"NO") << endl;

    return 0;
}
