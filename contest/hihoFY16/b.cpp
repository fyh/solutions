# include <iostream>
# include <iterator>
# include <map>
# include <vector>
# include <queue>
# include <cstring>
# include <algorithm>
# include <cstdio>
using namespace std;
typedef long long int lli;
# define testin freopen("in.txt", "r", stdin)

int n, m;

typedef pair<int,int> pii;
typedef map<int,int>::iterator addr;

int head;
map<int, addr > po;
map<int,int> me;

void doit(int i, int k) {
	while (true) {
        for (addr iter = me.begin(); iter != me.end(); ++iter) {
            addr nit = ++iter;
            if (nit == me.end()) break;
            --iter;
            int fi = nit->first;
            int be = iter->second;
            //cout << be << ", " << fi << ", " << k << endl;
            if (fi-be-1 >= k) {
                me[be+1] = be+k;
                po[i] = me.find(be+1);
                return ;
            }
        }
        if (head >= n) break;
        ++head;
		me.erase(po[head]);
	}
}

void solve() {
	cin >> n >> m;
	me.clear();
	head = 0;
	me.clear();

	me[-1] = -1;
	me[m] = m;

	for (int i = 0; i < n; ++i) {
		int k; cin >> k;
		doit(i+1, k);
	}
	for (int i = head+1; i <= n; ++i) {
		cout << i << ' ' << po[i]->first << endl;
	}
}

int main()
{
	 //testin;
	solve();
	return 0;
}
