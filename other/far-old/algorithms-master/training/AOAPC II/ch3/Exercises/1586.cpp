# include <iostream>
# include <cctype>
# include <cstdio>
char s[105];
double f[256];
int main()
{
    f['C'] = 12.01;
    f['H'] = 1.008;
    f['N'] = 14.01;
    f['O'] = 16.00;
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> s;
        double ans = 0;
        for (int i = 0; s[i]; ++i) {
            double cur = f[ s[i] ];
            int cnt = 0;
            while (s[i+1] && isdigit(s[i+1]) ) {
                cnt = cnt * 10 + s[i+1] - '0';
                ++i;
            }
            if (cnt <= 0) ++cnt;
            ans += cnt * cur;
        }
        printf("%.03f\n", ans);
    }

    return 0;
}
