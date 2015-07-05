# include <bits/stdc++.h>

# define testin freopen("in.txt", "r", stdin)

int n, d;
int pre = -1, cur;

int main()
{
    testin;
    long long int ans = 0;
    std::cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        std::cin >> cur;
        if (cur <= pre) {
            int t = ceil((pre+0.1-cur)/d);
            ans += t;
            cur += t * d;
        }
        pre = cur;
    }
    std::cout << ans << std::endl;

    return 0;
}
