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
