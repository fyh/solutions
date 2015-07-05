# include <map>
# include <string>
# include <iostream>
// # include <stdio.h>
std::map<std::string,int> mp;
char s[55];
int main()
{
    // freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        int t = mp[str]++;
        if (t) {
            std::cout << str << t << std::endl;
        } else std::cout << "OK" << std::endl;
    }
    return 0;
}

