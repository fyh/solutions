# include <cstring>
# include <iostream>
# include <algorithm>
using namespace std;
const int maxn = 105;
char s[maxn];
char t[maxn];
int is[26], it[26];
void cnt(char *str, int c[])
{
    for (int i = 0; i < 26; ++i) c[i] = 0;
    for (int i = 0; str[i]; ++i) ++c[ str[i]-'A' ];
}

int main()
{
    while (cin >> s >> t) {
        cnt(s, is);
        cnt(t, it);
        sort(is, is+26);
        sort(it, it+26);
        bool ans = true;
        for (int i = 0; i < 26; ++i) {
            if (is[i] != it[i]) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES":"NO") << endl;
    }

    return 0;
}
