class DancingForever
{
public:
    int n;
    bool used[105];
    int match[105];
    bool g[105][105];
    bool dfs(int c)
    {
        for (int i = 0; i < n; ++i) {
            if (g[c][i] && !used[i]) {
                used[i] = true;
                if (match[i]==-1 || dfs(match[i])) {
                    match[i] = c;
                    return true;
                }
            }
        }
        return false;
    }
    vector <int> getStablePairs(string G) {
        for (n = 1; n * n < G.size(); ++n) ;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = (G[i][j]=='Y');
            }
        }
        for (int i = 0; i < n; ++i) match[i] = -1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) used[j] = false;
            if (dfs(i)) {
                ++cnt;
            }
        }
        if (cnt == n) {
            vector<int> ret;
            for (int i = 0; i < n; ++i) {
                ret.push_back(match[i]);
                ret.push_back(i);
            }
        } else {
            return vector<int>(1, -1);
        }
    }
};
