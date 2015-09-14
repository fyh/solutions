# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int a, b;
int base;

int getMx(int x) {
    int ret = 1;
    while (x > 0) {
        ret = max(ret, x%10+1);
        x /= 10;
    }
    return ret;
}

int cnt[15];

int getVal(int x) {
    int n = 0;
    while (x > 0) {
        cnt[n++] = x%10;
        x/=10;
    }
    int ret = 0;
    int mul = 1;
    for (int i = 0; i < n; ++i) {
        ret += mul * cnt[i];
        mul *= base;
    }
    return ret;
}

int len(int x) {
    int ret = 0;
    while (x > 0) {
        x /= base;
        ++ret;
    }
    return ret;
}

int getSum() {
    base = max(getMx(a), getMx(b));
    return getVal(a) + getVal(b);
}

int main()
{
    cin >> a >> b;

    int sum = getSum();

    cout << len(sum) << endl;

    return 0;
}
