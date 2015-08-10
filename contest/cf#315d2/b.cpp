# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int maxn = 1e5+5;

bool mk[maxn];

int n;
int a[maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i]>n) a[i] = -1;
        else if (!mk[ a[i] ]) {
            mk[ a[i] ] = true;
        } else {
            a[i] = -1;
        }
    }

    int j = 1;
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        if (a[i] != -1) cout << a[i];
        else {
            while (mk[j]) ++j;
            cout << j;
            mk[j] = true;
        }
    }
    cout << endl;

    return 0;
}
