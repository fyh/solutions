# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;

int get(string str) {
    if (str == "rat") return 0;
    if (str == "woman" || str == "child") return 1;
    if (str == "man") return 2;
    return 3;
}

queue<string> Q[4];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string name, role;
        cin >> name >> role;
        Q[get(role)].push(name);
    }
    for (int i = 0; i < 4; ++i) {
        while (Q[i].size()) {
            cout << Q[i].front() << endl;
            Q[i].pop();
        }
    }

    return 0;
}
