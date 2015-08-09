# include <algorithm>
# include <iostream>
# include <stdio.h>
# include <string.h>
using namespace std;

const int maxn = 5005;

int n;
int a[maxn];
bool sell[maxn];
int arr[maxn], cnt;
int pre[maxn];
int fs[maxn];

// unsigned big integer
class ubint {
    const static int maxl = 2005;
    int len;
    char digits[maxl];

public:
    ubint(int b, int p = 1)
        : len(0)
    {
        memset(digits, 0, sizeof(digits));
        if (!b) {
            digits[len++] = 0;
            return ;
        }
        int t = b;
        while (b) {
            digits[len++] = b % 10;
            b /= 10;
        }
        for (int i = 1; i < p; ++i) {
            Multiply(t);
        }
    }

    void Multiply(int si)
    {
        int car = 0;
        for (int i = 0; i < len; ++i) {
            int tmp = si * digits[i] + car;
            car = tmp / 10;
            digits[i] = tmp % 10;
        }
        while (car) {
            digits[len++] = car % 10;
            car /= 10;
        }
    }

    void Add(ubint y)
    {
        int mx = std::max(len, y.len);
        int car = 0;
        for (int i = 0; i < mx; ++i) {
            int tmp = digits[i] + y.digits[i] + car;
            digits[i] = tmp % 10;
            car = tmp / 10;
        }
        if (car) {
            digits[mx++] = car;
        }
        len = mx;
    }

    void Show()
    {
        for (int i = len-1; i >= 0; --i) {
            printf("%d", digits[i]);
        }
        puts("");
    }
};

bool cmp(const int x, const int y) {return a[x] > a[y];}

void init() {
    scanf("%d", &n);
    char op[15];
    for (int i = 1; i <= n; ++i) {
        scanf("%s%d", op, &a[i]);
        if (op[0] == 's') {
            if (pre[ a[i] ]) {
                sell[i] = true;
                fs[i] = pre[a[i]];
            }
        } else {
            pre[ a[i] ] = i;
        }
    }
}

void solve(int l, int r) {
    if (l > r) return ;
    int mx = -1, ml, mr;
    for (int i = l; i <= r; ++i) {
        if (sell[i]) {
            int t = fs[i];
            if (l<=t&&t<=r) {
                if (mx < a[i]) {
                    mx = a[i];
                    ml = t;
                    mr = i;
                }
            }
        }
    }
    if (mx != -1) {
        arr[cnt++] = mx;
        solve(l, ml-1);
        solve(mr+1, r);
    }
}

int main()
{
    init();

    solve(1, n);

    sort(arr, arr+cnt);
    ubint ans(0);

    ubint cur(1);
    int pp = 0;
    for (int i = 0; i < cnt; ++i) {
        while (pp != arr[i]) {
            cur.Multiply(2);
            ++pp;
        }
        ans.Add(cur);
    }
    ans.Show();

    return 0;
}
