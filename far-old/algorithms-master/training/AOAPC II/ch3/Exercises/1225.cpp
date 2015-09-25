# include <iostream>
# include <cstring>
int main()
{
    int N, c[15], T;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        memset(c, 0, sizeof(c));
        for (int i = 1, t; i <= N; ++i) {
            t = i;
            while (t) {
                ++c[ t%10 ];
                t/=10;
            }
        }
        std::cout << c[0];
        for (int i = 1; i < 10; ++i) {
            std::cout << ' ' << c[i];
        }
        std::cout << std::endl;
    }
    return 0;
}
