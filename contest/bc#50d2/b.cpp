# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <iostream>
# include <math.h>

using namespace std;

# define testin freopen("in.txt", "r", stdin)

int n;
int x[25], y[25];
int id[105][105];

/*
cosa sina
-sina cosa
*/

# define PI (atan(1.0)*4)

int main()
{
   // testin;

    while (cin >> n) {
        memset(id, -1, sizeof(id));
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
            id[ x[i] ][ y[i] ] = i;
        }
        int ans = 0;
        for (int i = (0x1<<n)-1; i > 0; --i) {
            int c = 0;
            int cx = 0, cy = 0;
            int first = -1;
            for (int j = 0; j < n; ++j) {
                if ((i>>j)&0x1) {
                    if (first == -1) first = j;
                    ++c;
                    cx += x[j];
                    cy += y[j];
                }
            }
            if (c < 3) {
                continue;
            }
            int vx = x[first] * c - cx, vy = y[first] * c - cy;
            bool ok = true;
            for (int k = 1; k < c; ++k) {
                double nx = vx*cos(2*PI/c) - vy*sin(2*PI/c);
                double ny = vx*sin(2*PI/c) - vy*cos(2*PI/c);
                nx += cx, ny += cy;
                int tx = nx / c, ty = ny / c;
                if (0<=tx&&tx<=0 && 0<=ty&&ty<=9) {
                    int p = id[tx][ty];
                    if (p == -1 || !((i>>p)&0x1)) {
                        ok = false;
                        break;
                    }
                    vx = tx * c - cx, vy = ty * c - cy;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ++ans;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
