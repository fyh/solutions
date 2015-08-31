# include <bits/stdc++.h>
# define input freopen("input.txt", "r", stdin)
# define output freopen("output.txt", "w", stdout)
using namespace std;
typedef long long int lli;

int id;
int x, y;

int main()
{
    input;
    output;
    cin >> id;
    for (int i = 0; i < 3; ++i) {
        cin >> x >> y;
        if (x == y) continue;
        if (x == id) id = y;
        else if (y == id) id = x;
    }
    cout << id << endl;

    return 0;
}
