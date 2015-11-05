2# include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

ull t, w, b;

ull gcd(ull x, ull y) { return !y ? x:gcd(y,x%y); }

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> t >> w >> b;

    ull T = t;

    ull c = t / w / (b / gcd(w, b));

    ull ans = c * min(w, b);

    t -= c*w*(b/gcd(w,b));

    ans += min(t, min(w,b)-1);

    ull cc = gcd(ans, T);

    cout << (ans/cc) << "/" << (T/cc) << endl;

    return 0;
}
