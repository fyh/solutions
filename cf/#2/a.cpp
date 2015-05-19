# include <stdio.h>
# include <vector>
# include <map>
# include <iostream>

using namespace std;

map<string, int> sc;
multimap<int, string> mp;

int n;

# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;

    string name;
    int score;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name >> score;
        if (score < 0 || sc[name] < 0) sc[name] = -1;
        else {
            sc[name]+=score;
            mp.insert(pair<int,string>(sc[name], name));
        }
    }
    int mx = -1;
    for (multimap<int, string>::iterator it = mp.begin(); it != mp.end(); ++it) {
        if (it->first > mx && sc[it->second]>0) {
            mx = it->first;
            name = it->second;
        }
    }
    cout << name << endl;

    return 0;
}
