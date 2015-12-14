# include <bits/stdc++.h>
using namespace std;
# define speedup cin.tie(0), ios_base::sync_with_stdio(false)

typedef long long int lli;

const int maxm = 1e4+5;
const int maxn = 1e6+5;

char s1[maxm], s2[maxn];

vector<int> p[30];

void build()
{
    for (int i = 0; s1[i]; ++i) {
        int t = s1[i] - 'a';
        p[t].push_back(i);
    }
}

int main()
{
    speedup;

    cin >> s1 >> s2;

    build();

    int ans = 1;
    int cur = -1;
    for (int i = 0; s2[i]; ++i) {
        int t = s2[i] - 'a';

        if (p[t].empty()) {
            ans = -1;
            break;
        }

        auto q = lower_bound(p[t].begin(), p[t].end(), cur+1);
        if (q == p[t].end()) {
            ++ans;
            cur = p[t][0];
        } else {
            cur = *q;
        }
    }

    cout << ans << endl;

    return 0;
}
