# include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
int x = 105, y = 105;
int cx, cy;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i]%2) {
            ++cx;
            if (x == 105) x = i+1;
        } else {
            ++cy;
            if (y == 105) y = i+1;
        }
    }
    cout << (cx > cy ? y:x) << endl;

    return 0;
}
