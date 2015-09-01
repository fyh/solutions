# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;
map<string,int> go;

int main()
{
    string wi;
    int gc = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string te;
        cin >> te;
        ++go[te];
        if (go[te] > gc) {
            gc = go[te];
            wi = te;
        }
    }

    cout << wi << endl;

    return 0;
}
