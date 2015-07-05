// LCIS:
// http://www.csie.ntnu.edu.tw/~u91029/LongestCommonSubsequence.html
// http://www.cnblogs.com/wd-one/p/4470844.html

# include <bits/stdc++.h>

const int maxn = 505;

int n, m;
int a[maxn];
int b[maxn];

int dp[maxn];
int pre[maxn];
int sol[maxn];

void read(int &k, int *v) {
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) scanf("%d", v+i);
}

void solve() {
    for (int i = 0; i < n; ++i) {
        int mx = 0, p = -1;
        for (int j = 0; j < m; ++j) {
            if (a[i] > b[j] && mx < dp[j]) {
                    mx = dp[j];
                    p = j;
            } else if (a[i] == b[j]) {
                dp[j] = mx + 1;
                pre[j] = p;
            }
        }
    }
    int ans = 0, p;
    for (int i = 0; i < m; ++i) {
        if (ans < dp[i]) {
            ans = dp[p = i];
        }
    }
    for (int i = ans-1; i >= 0; --i) {
        sol[i] = b[p];
        p = pre[p];
    }
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i) {
        printf("%d ", sol[i]);
    }
    printf("\n");
}

# define testin freopen("in.txt", "r", stdin)

int main()
{
    // testin;

    read(n, a);
    read(m, b);
    solve();

    return 0;
}
