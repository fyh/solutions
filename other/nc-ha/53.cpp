# include <stdio.h>
# include <utility>
# include <queue>

const int maxn = 55;

int n;
int f[maxn*2];
int c[maxn*2];

int get(int x) {
    int r = 0;
    while (x != f[x]) {
        x = f[x];
        ++r;
    }
    return r;
}

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &c[i]); c[i]=-c[i];
        }
        for (int i = 0; i < maxn*2; ++i) f[i] = i;
        std::priority_queue< std::pair<int,int> > Q;
        for (int i = 0; i < n; ++i) {
            Q.push( std::make_pair(c[i], i) );
        }

        int t = n;
        while (Q.size() > 1) {
            std::pair<int,int> p = Q.top(); Q.pop();
            std::pair<int,int> q = Q.top(); Q.pop();
            f[ p.second ] = f[ q.second ] = t;
            c[t] = p.first + q.first;
            Q.push( std::make_pair(c[t], t) );
            ++t;
        }

        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += -c[i]*get(i);
        }
        while (Q.size()) Q.pop();

        printf("%d\n", s);
    }

    return 0;
}
