# include <bits/stdc++.h>
using namespace std;
# define speedup cin.tie(0), ios_base::sync_with_stdio(false)
typedef long long int lli;

int r, g, b;

int get(int t, int d) {
    return !t ? 0:d+30+(t-1)/2*3;
}

int main()
{
    speedup;

    cin >> r >> g >> b;

    cout << max(get(r,0), max(get(g,1), get(b,2))) << endl;

    return 0;
}
