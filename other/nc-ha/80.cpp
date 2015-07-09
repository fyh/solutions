char b[15][15];
bool v[15][15];
int sx, sy;
char s[5];
typedef std::pair<int,int> pii;
pii get_next(x, y, i, ch);
void check(int x, int y, char ch) {
    std::queue<pii> Q;
    Q.push(std::make_pair(x,y));
    v[x][y] = true;
    while (Q.size()) {
        pii p = Q.front(); Q.pop();
        for (int i = 0; i < 8; ++i) {
            pii q;
            bool t = get_next(x, y, ch, &q);
            if (t) {
                for (int j = 0; ; ++j) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (b[nx][ny] == ch) break;
                    b[nx][ny] = ch;
                    if (!v[nx][ny]) {
                        Q.push( std::make_pair(nx,ny) );
                        v[nx][ny] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    while (~scanf("%s", b[0])) {
        for (int i = 1; i < 8; ++i) {
            scanf("%s", b[i]);
        }
        scanf("%d%d%s", &sx, &sy, s);
        memset(v, false, sizeof(v));
        check(sx, sy, s);
    }

    return 0;
}
