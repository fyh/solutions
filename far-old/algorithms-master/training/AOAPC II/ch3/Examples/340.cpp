# include <cstring>
# include <iostream>
const int maxn = 1005;
int N;
int a[maxn], b[maxn], c[15], t[15];
bool isStrong[maxn];

int main()
{
    int ica = 0;
    while (std::cin >> N, N) {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < N; ++i) {std::cin >> a[i]; ++c[ a[i] ];}
        std::cout << "Game "<<++ica << ":" <<std::endl;
        while (1) {
            for (int i = 0; i < 10; ++i) t[i] = c[i];
            int cnt = 0;
            for (int i = 0; i < N; ++i) {std::cin >> b[i]; isStrong[i] = false; if (!b[i]) ++cnt;}
            if (cnt >= N) break;
            int ans1 = 0, ans2 = 0;
            for (int i = 0; i < N; ++i) {
                if (a[i] == b[i]) {
                    isStrong[i] = true;
                    ++ans1;
                    --t[ a[i] ];
                }
            }
            for (int i = 0; i < N; ++i) {
                if (!isStrong[i] && t[b[i]]>0 ) {
                    --t[ b[i] ];
                    ++ans2;
                }
            }
            std::cout << "    (" << ans1 << "," << ans2 <<")" << std::endl;
        }
    }

    return 0;
}
