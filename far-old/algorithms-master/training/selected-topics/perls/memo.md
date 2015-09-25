## std::map 用法 ##


```
# include <map>
# include <iostream>
using namespace std;

typedef long long int lli;

int main()
{
    map<lli, double> mem;

    mem.clear();

    lli a = 0x123456789;
    mem[a] = 3.1415;

    cout << mem.find(a)->second << endl;
    cout << mem.find(a)->first << endl;

    lli b = 0x1234567912;

    if ( mem.find(b) != mem.end() ) {
        cout << "find" << endl;
    } else {
        cout << "non-exist" << endl;
    }

    cout << mem.find(b)->second << endl;
    cout << mem.find(b)->first << endl;

    cout << mem.end()->first << endl;
    cout << mem.end()->second << endl;

    return 0;
}

```


```
# include <map>
# include <vector>
# include <string>
# include <iostream>

int main()
{
    std::map< std::string, std::vector< std::string > > metaDict;
    std::map< std::string, std::vector< std::string > >::iterator it;

    metaDict["DimSize"].push_back("1");
    metaDict["DimSize"].push_back("2");
    metaDict["DimSize"].push_back("3");

    it = metaDict.find("DimSize");

    if ( it != metaDict.end() ) {
        for (unsigned int i = 0; i < it->second.size(); ++i) {
            std::cout << it->second[i] << std::endl;
        }
    }

    return 0;
}

```

## problems ##
TC SRM 645 div2 1000