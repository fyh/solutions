// 4 WA
// 1. �Ѿ�turn over���ַ���Ȼ������Ҳ�����ٴβµ����ַ�ʱ������wrong guessҲ������correct guess
// 2. �������һ���´���ַ�����guess���ظ����֣�ÿ�γ��ֶ���Ϊһ��wrong guess

# include <cstring>
# include <cstdio>
# include <iostream>

using namespace std;

const int maxn = 1005;

int id;
char puzzle[maxn];
char guess[maxn];

int len;
int cnt[256];
bool flg[256];

int main()
{
    while (cin >> id, id != -1) {
        scanf("%s%s", puzzle, guess);
        memset(cnt, 0, sizeof(cnt));
        memset(flg, false, sizeof(flg));
        len = 0;
        for (int i = 0; puzzle[i]; ++i) ++cnt[ puzzle[i] ], ++len, flg[ puzzle[i] ] = true;
        int win = 0, wrong_guess = 0;
        for (int i = 0; guess[i]; ++i) {
            if (cnt[ guess[i] ] != 0) {
                len -= cnt[ guess[i] ];
                cnt[ guess[i] ] = 0;
                if ( len <= 0 ) {
                    win = 1;
                    break;
                }
            } else if (!flg[ guess[i] ]) {
                ++wrong_guess;
                if ( wrong_guess >= 7) {
                    win = -1;
                    break;
                }
            }
        }
        cout << "Round " << id << endl;
        if (win == 1) cout << "You win." << endl;
        else if (win == -1) cout << "You lose." << endl;
        else cout << "You chickened out." << endl;
    }

    return 0;
}
