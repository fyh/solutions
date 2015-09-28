# include <bits/stdc++.h>
using namespace std;

bool isP(int x) {
    for (int i = 2; i < x; ++i) if (x%i == 0) return false;
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = a+1; i < b; ++i) {
        if (isP(i)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (isP(b)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
