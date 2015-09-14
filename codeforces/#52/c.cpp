# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1005;
vector<int> su[maxn];
string na[maxn];
int n;

map<string> Id;

char buf[maxn];
int build(int l, int r) {
    //
}

int main()
{
    build(0, strlen(buf)-1);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < su[i].size(); ++j) {
            if (na[i]==na[j]) ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
