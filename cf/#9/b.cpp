# include <bits/stdc++.h>

typedef long long int lli;

int n, vb, vs;
lli xu, yu;

const int maxn = 105;

lli d2[maxn];
lli x[maxn];
int r[maxn];

double get(int i) {
    return 1.0*x[i]*vs + 1.0*sqrt(d2[i])*vb;
}

bool eql(double x, double y) {
    return fabs(x-y) <= 1e-6;
}

bool cmp(const int a, const int b) {
    if (eql(get(a), get(b))) return d2[a]<=d2[b];
    return get(a) <= get(b);
}

int main()
{
    std::cin >> n >> vb >> vs;
    --n; int t; std::cin >> t;
    for (int i = 0; i < n; ++i) std::cin >> x[i];
    std::cin >> xu >> yu;
    for (int i = 0; i < n; ++i) d2[i] = (x[i]-xu)*(x[i]-xu)+yu*yu;
    for (int i = 0; i < n; ++i) r[i] = i;
    std::sort(r, r+n, cmp);
    std::cout << r[0]+2 << std::endl;

    return 0;
}
