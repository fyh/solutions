/*
如果将所有'?'用')'替代，剩下的只需要考虑选择哪些位置的')'改变为'('
两条规则：
1. 合法，'('的数目和')'相等，且'('的前缀数目不小于')'
2. 最小，考虑两个不同位置，选择哪一个保证结果更优，从而得出最优解的条件
*/

# include <queue>
# include <utility>
# include <stdio.h>
const int maxn = 50005;
char s[maxn];
typedef std::pair<int,int> pii;
std::priority_queue<pii> Q;
int main()
{
    scanf("%s", s);
    int b = 0;
    long long int ans = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(') ++b;
        else if (s[i] == ')') --b;
        else {
            s[i] = ')';
            --b;
            int x, y;
            scanf("%d%d", &x, &y);
            ans += y;
            Q.push( std::make_pair(y-x, i) );
        }
        if (b < 0) {
            if (Q.empty()) break;
            pii p = Q.top(); Q.pop();
            s[p.second] = '(';
            ans -= p.first;
            b += 2;
        }
    }
    if (!b) printf("%I64d\n%s\n", ans, s);
    else printf("-1\n");
    return 0;
}

