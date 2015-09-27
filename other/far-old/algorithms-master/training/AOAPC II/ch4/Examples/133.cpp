// 16:02
# include <cstdio>
# include <iostream>
using namespace std;

const int maxn = 25;

int N, k, m;

int next[maxn];
int pre[maxn];

void del(int x)
{
    int l = pre[x], r = next[x];
    next[l] = r;
    pre[r] = l;
}

int main()
{
    while (cin >> N >> k >> m, N||k||m) {
        for (int i = 1; i <= N; ++i) next[i] = i%N + 1;
        for (int i = 1; i <= N; ++i) pre[i] = (i-1 + N-1) % N + 1;
        int cnt = 0;
        int i = 1, j = N;
        bool first = true;
        while ( cnt < N ) {
            for (int x = 1; x < k; ++x) i = next[i];
            for (int x = 1; x < m; ++x) j = pre[j];
            ++cnt;
            if (first) first = false;
            else cout << "," ;
            if (i == j) {
                del(i);
                printf("%3d", i);
                i = next[i];
                j = pre[j];  // WA : j = next[j];
            } else {
                //// WA : 后一次删除对 i 的影响
                int ti = next[i];
                if (ti == j) ti = next[j];
                //
                del(i);
                del(j);
                printf("%3d%3d", i, j);
                ++cnt;
                j = pre[j];
                i = ti;
            }
        }
        cout << endl;
    }

    return 0;
}
