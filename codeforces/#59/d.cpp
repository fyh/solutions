# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

int a, b, c, d, n;
int x[30];

char bd[105][105];

queue<pii> Q;

int main()
{
    cin >> a >> b >> c >> d >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];

    puts("YES");

    int dir = 1;
    pii st = make_pair(1,1);
    if (a%2 == 1) st.first = b, dir = -dir;

    memset(bd, '.', sizeof(bd));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            bd[st.first][st.second] = i+'a';
            st.first += dir;
            if (st.second < a) {
                if (st.first > b) {
                    st.first = b;
                    ++st.second;
                    dir = -dir;
                } else if (st.first < 1) {
                    st.first = 1;
                    ++st.second;
                    dir = -dir;
                }
            } else if (st.second == a) {
                if (st.first < 1) {
                    st.first = 1;
                    ++st.second;
                    dir = -dir;
                }
            } else if (st.second > a) {
                if (st.first > d) {
                    st.first = d;
                    ++st.second;
                    dir = -dir;
                } else if (st.first < 1) {
                    st.first = 1;
                    ++st.second;
                    dir = -dir;
                }
            }
        }
    }

    for (int j = 1; j <= max(b,d); ++j) {
        for (int i = 1; i <= a+c; ++i) {
            putchar(bd[j][i]);
        }
        puts("");
    }

    return 0;
}
