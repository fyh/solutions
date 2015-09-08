# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;
vector<string> lines;
string word;

int main()
{
    cin >> word >> n;
    for (int i = 0; i < n; ++i) {
        string tmp; cin >> tmp;
        lines.push_back(tmp);
    }

    sort(lines.begin(), lines.end());

    bool fi = false;
    for (int i = 0; i < n; ++i) {
        if (lines[i].length() < word.length()) continue;
        bool ok = true;
        for (int j = 0; j < word.length(); ++j) {
            if (word[j] != lines[i][j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << lines[i] << endl;
            fi = true;
            break;
        }
    }

    if (!fi) cout << word << endl;

    return 0;
}
