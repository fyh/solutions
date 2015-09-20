# include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ull;

ull k;

int Get(ull k) {
    if (k<=1) return 0;
    else {
        ull t = (ull)1<<63;
        while (t > 2*k) {
            t >>= 1;
        }
        if (t == 2*k) return 0;
        else return 1-Get(t-k);
    }
}

int main()
{
    freopen("A-large-practice.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    cin >> T;
    for (int ica = 1; ica <= T; ++ica) {
        cin >> k;
        cout << "Case #" << ica << ": " << Get(k) << endl;
    }
    return 0;
}

