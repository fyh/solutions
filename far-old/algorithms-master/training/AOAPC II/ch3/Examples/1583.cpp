# include <iostream>
const int maxn = 100005;
int a[maxn];
int digitSum(int x) {
    int ret = 0;
    while (x) {
        ret += x%10;
        x /= 10;
    }
    return ret;
}
void printTable(void)
{
    for (int i = 0; i < maxn; ++i) {
        int t = i + digitSum(i);
        if (t >= maxn) continue;
        if (!a[t]) a[t] = i;
    }
}
int main()
{
    printTable();
    int T;
    std::cin >> T;
    while (T--) {
        int x; std::cin >> x; std::cout << a[x] << std::endl;
    }
}
