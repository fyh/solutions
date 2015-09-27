# include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

string na;
map<string,int> pr;
vector<string> an;

int n;

bool cmp(const string &a, const string &b) {
    if (pr[a] == pr[b]) return strcmp(a.c_str(), b.c_str())<=0;
    return pr[a] >= pr[b];
}

void doit() {
    string a, b, c, d, e;
    cin >> a >> b >> c >> d;
    int ad = 0;
    if (b == "likes") {
        b = c.substr(0, c.length()-2);
        ad = 5;
    } else {
        cin >> e;
        b = d.substr(0, d.length()-2);
        if (e == "wall") {
            ad = 15;
        } else {
            ad = 10;
        }
    }
    pr[a] += 0;
    pr[b] += 0;
    if (a == na) pr[b] += ad;
    if (b == na) pr[a] += ad;
}

int main()
{
    // freopen("in.txt", "r", stdin);

    cin >> na >> n;
    for (int i = 0; i < n; ++i) {
        doit();
    }
    for (auto it = pr.begin(); it != pr.end(); ++it) {
        an.push_back(it->first);
    }
    sort(an.begin(), an.end(), cmp);
    for (int i = 0; i < an.size(); ++i) {
        if (an[i] != na) cout << an[i] << endl;
    }

    return 0;
}
