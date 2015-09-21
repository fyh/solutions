# include <bits/stdc++.h>
using namespace std;

int n;
char s[105];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (strlen(s) <= 10) cout << s << endl;
        else {
            cout << s[0] << strlen(s)-2 << s[strlen(s)-1] << endl;
        }
    }

    return 0;
}
