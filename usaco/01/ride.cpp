/*
ID: yajunwf1
LANG: C++
TASK: ride
*/
# include <bits/stdc++.h>
using namespace std;
# define datain freopen("ride.in", "r", stdin)
# define dataout freopen("ride.out", "w", stdout)

int get(char *s) {
    int ret = 1;
    for (int i = 0; s[i]; ++i) {
        ret *= (s[i]-'A'+1);
        ret %= 47;
    }
    return ret;
}

int main()
{
    datain;
    dataout;

    char s[10], t[10]; cin >> s >> t;

    cout << (get(s) == get(t) ? "GO":"STAY") << endl;

    return 0;
}
