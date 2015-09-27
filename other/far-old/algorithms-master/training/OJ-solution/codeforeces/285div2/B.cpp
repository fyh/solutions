# include <iostream>
# include <string>
# include <map>
# include <vector>
int q;
std::map< std::string, std::string > mp;
std::map< std::string, bool > rmp;
std::vector< std::string > vec;
std::string x, y;
int main()
{
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::cin >> x >> y;
        if (!rmp[x]) vec.push_back(x);
        mp[x] = y;
        rmp[y] = true;
    }
    std::cout << vec.size() << std::endl;
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ' ';
        std::string cur = vec[i];
        while (!mp[cur].empty()) cur = mp[cur];
        std::cout << cur << std::endl;
    }
    return 0;
}
