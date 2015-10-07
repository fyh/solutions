/*
ID: yajunwf1
LANG: C++11
TASK: namenum
*/
# include <bits/stdc++.h>
using namespace std;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
typedef long long int lli;

multimap<lli, string> M;
/*
2: A,B,C     5: J,K,L    8: T,U,V
          3: D,E,F     6: M,N,O    9: W,X,Y
          4: G,H,I     7: P,R,S
*/
int mc(int ch) {
    if (ch <= 'O') return (ch-'A')/3+2;
    if (ch <= 'S') return 7;
    if (ch <= 'V') return 8;
    return 9;
}

lli get(string cur) {
    lli ret = 0;
    for (int i = 0; i < cur.length(); ++i) {
        ret = ret*10 + mc(cur[i]);
    }
    return ret;
}

void init() {
    ifstream di("dict.txt");
    string cur;
    if (di.is_open()) {
        while (getline(di, cur)) {
            M.insert( make_pair(get(cur), cur) );
        }
    }
}

int main()
{
    init();

    rdio(namenum);

    lli n;
    cin >> n;
    if (M.count(n) > 0) {
        for (auto it = M.equal_range(n).first; it != M.equal_range(n).second; ++it) {
            cout << it->second << endl;
        }
    } else cout << "NONE" << endl;

    return 0;
}
