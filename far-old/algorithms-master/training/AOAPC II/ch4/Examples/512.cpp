# include <iostream>
# include <algorithm>
# include <vector>
# include <cstdio>
using namespace std;
class cell{
public:
    int ox, oy;
    int cx, cy;
    bool disappear;
    cell(int x, int y) :ox(x), oy(y), cx(x), cy(y){ disappear = false; }
    void ecg(int r1, int c1, int r2, int c2) {
        if (cx==r1&&cy==c1) cx = r2, cy = c2;
        else if (cx==r2&&cy==c2) cx = r1, cy = c1;
    }
    void delr(int row) {if(cx == row) disappear = true;else if (row < cx) --cx;}
    void delc(int col) {if(cy == col) disappear = true;else if (col < cy) --cy;}
    void insr(int row) {if(cx >= row) ++cx; }
    void insc(int col) {if(cy >= col) ++cy; }
    void printState(void)
    {
        if (disappear) {
            printf("Cell data in (%d,%d) GONE\n", ox, oy);
        } else {
            printf("Cell data in (%d,%d) moved to (%d,%d)\n", ox, oy, cx, cy);
        }
    }
};

const int max_od = 1005;
char od[max_od][5];
vector<int> odp[max_od];
# define decrep for (int k = odp[i].size()-1; k >= 0; --k)
# define testin freopen("in.txt", "r", stdin)
int main()
{
    testin;

    int r, c;
    int ica = 0;
    while (cin>>r>>c, r||c) {
        int n, m;
        cin >> n;
        for (int i = 0; i < n; ++i) odp[i].clear();
        for (int i = 0, x, cnt; i < n; ++i) {
            cin >> od[i];
            if (od[i][0] == 'E') cnt = 4;
            else cin >> cnt;
            for (int ii = 0, x; ii < cnt; ++ii) {
                cin >> x;
                odp[i].push_back(x);
            }
            if (od[i][0] != 'E') sort(odp[i].begin(), odp[i].end());
        }
        cin >> m;
        if (ica) cout << endl;
        cout << "Spreadsheet #" << ++ica << endl;
        for (int j = 0, x, y; j < m; ++j) {
            cin >> x >> y;
            cell cur(x, y);
            for (int i = 0; i < n; ++i) {
                if (od[i][0] == 'E') cur.ecg(odp[i][0], odp[i][1], odp[i][2], odp[i][3]);
                else if (od[i][0] == 'D') {
                    if (od[i][1] == 'R') {
                        decrep cur.delr(odp[i][k]);
                    } else {
                        decrep cur.delc(odp[i][k]);
                    }
                } else {
                    if (od[i][1] == 'R') {
                        decrep cur.insr(odp[i][k]);
                    } else {
                        decrep cur.insc(odp[i][k]);
                    }
                }
            }
            cur.printState();
        }
    }

    return 0;
}
