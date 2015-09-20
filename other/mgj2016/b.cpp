# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <map>
# include <set>
using namespace std;

# define testin freopen("in.txt", "r", stdin)

int n, m;

int main()
{
    cin >> n >> m;
    int ans = 0;
    int pre = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (pre+x <= m) {
            pre += x;
        } else {
            ++ans;
            pre = x;
        }
    }
    cout << ans + 1 << endl;

    return 0;
}
