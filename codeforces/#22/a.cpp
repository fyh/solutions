# include <bits/stdc++.h>
using namespace std;

int n;
int a[105];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);

    bool fi = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[0]) {
            cout << a[i] << endl;
            fi = true;
            break;
        }
    }
    if (!fi) cout << "NO" << endl;

    return 0;
}
