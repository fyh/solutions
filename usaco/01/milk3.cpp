/*
ID: yajunwf1
LANG: C++11
TASK: milk3
*/
# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
# define rdio(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

int a, b, c;

set<int> s;

map<int,map<int,map<int,int> > >M;

void dfs(int x, int y, int z) {
    if (x == 0) s.insert(z);
    if (M[x][y][z] > 0) return ;
    ++M[x][y][z];
    if (x!=0) {
        if (x+y <= b) dfs(0, x+y, z);
        else if (y != b) dfs(x+y-b, b, z);

        if (x+z <= c) dfs(0, y, z+x);
        else if (z != c) dfs(x+z-c, y, c);
    }
    if (y!=0) {
        if (x+y<=a) dfs(x+y,0,z);
        else if (x!=a) dfs(a,x+y-a,z);

        if (y+z<=c) dfs(x,0,z+y);
        else if (z!=c) dfs(x,y+z-c,c);
    }
    if (z!=0) {
        if (x+z<=a) dfs(x+z, y, 0);
        else if (x!=a) dfs(a, y, x+z-a);

        if (y+z<=b) dfs(x,y+z,0);
        else if (y!=b) dfs(x,b,y+z-b);
    }
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    rdio(milk3);

    cin >> a >> b >> c;

    dfs(0, 0, c);

    bool first = true;
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (first) first = false;
        else cout << ' ';
        cout << *it;
    }
    cout << endl;

    return 0;
}
