# include <stdio.h>
# include <queue>
std::queue<int> p, q;

int n;
int main()
{
    scanf("%d", &n);
    int k1, k2;
    scanf("%d", &k1);
    for (int i = 0; i < k1; ++i) {
        int x; scanf("%d", &x);
        p.push(x);
    }
    scanf("%d", &k2);
    for (int i = 0; i < k2; ++i) {
        int x; scanf("%d", &x);
        q.push(x);
    }

    int maxn = 150000;
    int i = 0;
    while (i < maxn) {
        if (p.empty()) {
            printf("%d ", i);
            puts("2");
            break;
        } else if (q.empty()) {
            printf("%d 1\n", i);
            break;
        } else {
            int x = p.front(); p.pop();
            int y = q.front(); q.pop();
            if (x > y) {
              //  printf("%d %d %d\n", x, y, q.size());
                p.push(y); p.push(x);
            } else {
                q.push(x); q.push(y);
            }
            ++i;
        }
    }

    if (i >= maxn) puts("-1");

    return 0;
}
