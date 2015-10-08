# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    int n;
    cin >> n;
    lli ans = 0, cnt = 0;
    int pre;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (!i) cnt = 1, pre = x;
        else {
            if (x == pre) ++cnt;
            else {
                ans += (cnt+1)*cnt/2;
                cnt = 1;
                pre = x;
            }
        }
    }
    ans += (cnt+1)*cnt/2;
    cout << ans << endl;

    return 0;
}
