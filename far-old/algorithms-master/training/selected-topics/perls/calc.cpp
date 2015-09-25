int calc(int n, int m) {
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i*j > n) break;
            ++ret;
        }
    }
    return ret;
}
