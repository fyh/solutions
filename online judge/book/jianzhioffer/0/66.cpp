/*
http://www.nowcoder.com/books/coding-interviews/6e5207314b5241fb83f2329e89fdecc8
*/
# include <iostream>
# include <map>
using namespace std;
class Solution {
private:
    int cnt;
    int r, c;
    int k;
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
    map< pair<int,int>, int> vis;
public:
    int ds(int x) {
        int r = 0;
        while (x > 0) r+=x%10, x/=10;
        return r;
    }
    bool ok(int x, int y) {
        return ds(x)+ds(y) <= k;
    }
    void dfs(int x, int y) {
        if (!ok(x,y)) return ;
        vis[ make_pair(x, y) ] = 1;
        ++cnt;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0<=nx&&nx<r && 0<=ny&&ny<c && !vis[ make_pair(nx,ny) ]) {
                dfs(nx, ny);
            }
        }
    }
	int movingCount(int threshold, int rows, int cols)
	{
	    cnt = 0;
	    k = threshold;
	    r = rows;
	    c = cols;
	    vis.clear();
	    dfs(0, 0);
	    return cnt;
	}
};
Solution s;
int main()
{
    cout << s.movingCount(1, 2, 2);
    return 0;
}
