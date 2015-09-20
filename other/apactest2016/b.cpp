# include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

double a[1005];

int main()
{
    freopen("B-large-practice.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T; cin >> T;
    for (int ica = 1; ica <= T; ++ica) {
        cout << "Case #" <<ica << ":" << endl;
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; ++i) cin >> a[i];
        for (int i = 0; i < M; ++i) {
            int L, R;
            cin >> L >> R;
            long double ans = 1.0;
            for (int j = L; j <= R; ++j) {
                ans *= pow(a[j], 1.0/(R-L+1));
            }
            printf("%.9llf\n", ans);
        }
    }

    return 0;
}
