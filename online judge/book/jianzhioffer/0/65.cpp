/*
http://www.nowcoder.com/books/coding-interviews/c61c6999eecb4b8f88a98f66b273a3cc
*/
# include <iostream>
using namespace std;
class Solution {
private:
    bool ok;
    int r, c;
    char *m;
    char *s;
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
    void dfs(int x, int n) {
        if (!s[n]) {
            ok = true;
            return ;
        }
        int xi = x / c, yi = x % c;
        for (int i = 0; i < 4; ++i) {
            int nxi = xi + dx[i];
            int nyi = yi + dy[i];
            if (0<=nxi&&nxi<r && 0<=nyi&&nyi<c) {
                int nx = nxi*c + nyi;
                if (m[nx] == s[n]) {
                    m[nx] = '#';
                    dfs(nx, n+1);
                    m[nx] = s[n];
                }
            }
        }
    }
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
	    if (str == NULL) return true;
	    r = rows;
	    c = cols;
	    m = matrix;
	    s = str;
	    ok = false;
	    for (int i = 0; !ok && matrix[i]; ++i) {
	        if (matrix[i] == str[0]) {
	            matrix[i] = '#';
	            dfs(i, 1);
	            matrix[i] = str[0];
	        }
	    }
	    return ok;
	}
};

int main()
{
    char x[] = "abcesfcsadee";
    char y[] = "bcced";
    Solution ss;
    cout << ss.hasPath(x, 3, 4, y);
    return 0;
}
