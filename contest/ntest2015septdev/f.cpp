# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
# include <map>
# include <set>
# include <vector>
# include <queue>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

# define testin freopen("in.txt", "r", stdin)

int cd[15], ca[30];

const int maxn = 1e5+5;

int u, v;
char s[maxn];

priority_queue<pii, vector<pii>, greater<pii>> Q;

int ID;
int getId() {
    return ID ++;
}

vector<int> G[maxn*3];

vector<int> num;
vector<lli> va;
vector<lli> vb;

void dfs(int cur, int c0, int c1) {
    if (G[cur].size() == 0) {
        va.push_back(c0*u+c1*v);
        vb.push_back(c0*v+c1*u);
    } else {
        dfs(G[cur][0], c0+1, c1);
        dfs(G[cur][1], c0, c1+1);
    }
}

void solve() {
    num.clear();
    va.clear();
    vb.clear();
    memset(cd, 0, sizeof(cd));
    memset(ca, 0, sizeof(ca));
    for (int i = 0; s[i]; ++i) {
        if (isdigit(s[i])) {
            ++cd[ s[i]-'0' ];
        } else ++ca[ s[i]-'a' ];
    }

    while (!Q.empty()) Q.pop();
    for (int i = 0; i < maxn*3; ++i) G[i].clear();
    ID = 1;
    for (int i = 0; i < 10; ++i) {
        if (cd[i]) {
            Q.push(make_pair(cd[i], getId()));
            num.push_back(cd[i]);
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (ca[i]) {
            Q.push(make_pair(ca[i], getId()));
            num.push_back(ca[i]);
        }
    }

    if (Q.size() == 1) {
        lli ans = min(u, v);
        pii cur = Q.top(); Q.pop();
        ans *= cur.first;
        cout << ans << endl;
        return ;
    }

    while (true) {
        if (Q.size() <= 1) {
            pii cur = Q.top(); Q.pop();
            dfs(cur.second, 0, 0);
            lli tmp = 0, tmp2 = 0;
            // cout << va.size() << ", " << vb.size() << "," << num.size() << endl;
            sort(va.begin(), va.end());
            sort(vb.begin(), vb.end());
            sort(num.begin(), num.end());
            reverse(num.begin(), num.end());
            for (int i = 0; i < num.size(); ++i) {
                tmp += va[i] * num[i];
                tmp2 += vb[i] * num[i];
            }
            if (tmp < tmp2) cout << tmp;
            else cout << tmp2;
            cout << endl;

            return ;
        }
        pii x = Q.top(); Q.pop();
        pii y = Q.top(); Q.pop();
        pii z = make_pair(x.first+y.first, getId());
        G[z.second].push_back(x.second);
        G[z.second].push_back(y.second);
        Q.push(z);
    }
}

int main()
{
    // testin;

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%s", &u, &v, s);
        solve();
    }

    return 0;
}

