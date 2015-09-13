# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e6+5;

int n;
lli x[maxn], y[maxn];
int r[maxn];

lli lmt = 250000;

lli llabs(int c) {
    return c < 0 ? -c : c;
}

bool doit() {
    lli sum = 0;
    for (int i = n-1; i >= 1; --i) {
        int t = rand() % i;
        swap(r[i], r[t]);
        if (i+1 < n) {
            int a = r[i+1], b = r[i];
            sum += llabs(x[a]-x[b]) + llabs(y[a]-y[b]);
            if (sum > lmt) return false;
        }
    }
    if (sum <= lmt) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", r[i]+1);
        }
        puts("");
        return true;
    }
}

bool cmp(const int &a, const int &b) {
    return x[a]+y[a] <= x[b]+y[b];
}
bool cmpx(const int &a, const int &b) {
    return x[a] <= x[b];
}

int main()
{
    srand(time(NULL));

    lmt = lmt * 10000;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) r[i] = i;
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
    sort(r, r+n, cmpx);
    sort(r, r+n, cmp);

    if (n <= 1000) {
        for (int i = 1; i <= n; ++i) printf("%d ", i);
        puts("");
    } else {
        while (!doit()) ;
    }

    return 0;
}
