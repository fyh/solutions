# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
# include <map>
# include <set>
# include <vector>
# include <queue>
using namespace std;
typedef long long int lli;

# define testin freopen("in.txt", "r", stdin)

int h;
priority_queue<int> Q;

int main()
{
    // testin;

    int T;
    scanf("%d", &T);
    while (T--) {
        while (!Q.empty()) Q.pop();
        scanf("%d", &h);
        for (int i = 0; i < h; ++i) {
            int x; scanf("%d", &x);
            if (x>0) Q.push(x);
        }
        int ans = 0;
        while (Q.size() >= 3) {
            int x = Q.top(); Q.pop();
            if (x <= 1) {
                ans += (Q.size()+1)/6;
                break;
            } else {
                int y = Q.top(); Q.pop();
                if (y <= 1) {
                    if (Q.size()>=3) {
                        for (int i = 0; i < 3; ++i) Q.pop();
                    } else break;
                    ++ans;
                    if (x>2) Q.push(x-2);
                } else {
                    int z = Q.top(); Q.pop();
                    if (z <= 1) {
                        if (Q.size() >= 1) Q.pop();
                        ++ ans;
                        if (y > 2) Q.push(y - 2);
                        if (x > 2) Q.push(x - 2);
                    } else {
                        ans += z/2;
                        int t = z / 2;
                        x -= t*2, y -= t * 2, z -= t * 2;
                        if (x > 0) Q.push(x);
                        if (y > 0) Q.push(y);
                        if (z > 0) Q.push(z);
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}

