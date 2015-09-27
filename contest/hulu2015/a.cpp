# include <cstring>
# include <algorithm>
# include <iostream>
using namespace std;
typedef long long int lli;

const int maxk = 15;

int N, M, L, K;

int dx[maxk], dy[maxk];

bool ok(int x, int y) {
    return 1<=x&&x<=N && 1<=y&&y<=M;
}

int get(int x, int y) {
    int ret = 0;
    for (int i = 0; i < L; ++i) {
        if (ok(x+dx[i], y+dy[i])) ++ret;
    }
    return ret;
}

int main()
{
    cin >> N >> M >> L >> K;
    for (int i = 0; i < L; ++i) cin >> dx[i] >> dy[i];
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (get(i,j)==K) ++ans;
        }
    }
    cout << ans << endl;
}
