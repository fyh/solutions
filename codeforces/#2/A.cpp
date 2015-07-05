# include <iostream>
# include <string>
# include <map>
# include <stdio.h>

using namespace std;

int n;
const int maxn = 1005;
map<string,int> sc, m2;
string name[maxn];
int score[maxn];


# define testin freopen("in.txt", "r", stdin)

int main()
{
    // testin;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name[i] >> score[i];
        sc[ name[i] ] += score[i];
    }

    int mx = -1;
    for (map<string,int>::iterator it = sc.begin(); it != sc.end(); ++it) {
        mx = max(mx, it->second);
    }
    for (int i = 0; i < n; ++i) {
        m2[ name[i] ] += score[i];
        if (sc[name[i]] == mx && m2[name[i]] >= mx) {
            cout << name[i] << endl;
            break;
        }
    }

    return 0;
}
