# include <bits/stdc++.h>
using namespace std;

int l, d, v, g, r;

int main()
{
    cin >> l >> d >> v >> g >> r;

    double ans = l * 1.0 / v;
    int a = d / v, b = d % v;
    int t = a % (g + r);
    if (g<=t&&t<g+r) {
        ans += (g+r - t - b*1.0/v);
    }
    printf("%.9f\n", ans);

    return 0;
}
