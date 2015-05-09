# include <vector>
# include <string>
using namespace std;
class OddEvenTree {
public:
    vector<int> getTree(vector<string> G) {
        int n = G.size();
        vector<int> vec;
        bool ok = true;
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (G[i][k]==G[k][j] && G[i][j]!='E') ok = false;
                    if (G[i][k]!=G[k][j] && G[i][j]!='O') ok = false;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (G[i][i] != 'E') ok = false;
            for (int j = 0; j < i; ++j) {
                if (G[i][j] != G[j][i]) ok = false;
                if (G[i][j] == 'O' && cnt < n-1) {
                    vec.push_back(i);
                    vec.push_back(j);
                    ++cnt;
                }
            }
        }
        if (!ok || cnt != n-1) return vector<int> (1, -1);
        return vec;
    }
};

{"EOO",
"OEO",
"OOE"}

{"EE",
"EE"}
