# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <iostream>

using namespace std;

# define testin freopen("in.txt", "r", stdin)
# define testout freopen("out.txt", "w", stdout);

long long int ans[]  = {
 0LL, 1LL, 2LL, 3LL, 5LL, 8LL, 12LL, 20LL, 33LL, 54LL, 88LL, 143LL, 232LL, 376LL, 609LL, 986LL, 1596LL, 2583LL, 4180LL, 6764LL, 10945LL, 17710LL, 28656LL, 46367LL, 75024LL, 121392LL, 196417LL, 317810LL, 514228LL, 832039LL, 1346268LL, 2178308LL, 3524577LL, 5702886LL, 9227464LL, 14930351LL, 24157816LL, 39088168LL, 63245985LL, 102334154LL, 165580140LL, 267914295LL, 433494436LL, 701408732LL, 1134903169LL, 1836311902LL, 2971215072LL, 4807526975LL, 7778742048LL, 12586269024LL, 20365011073LL, 32951280098LL, 53316291172LL, 86267571271LL, 139583862444LL, 225851433716LL, 365435296161LL, 591286729878LL, 956722026040LL, 1548008755919LL, 2504730781960LL, 4052739537880LL, 6557470319841LL, 10610209857722LL, 17167680177564LL, 0LL,
};

int n;
long long int f[65][65][65];

void get(int cnt, int total, int cnts, long long int &cur) {
    if (total == 0 || cnt == cnts) {
        if (cnt == cnts) ++cur;
    } else {
        for (int i = 1; i < total; ++i) {
            get(cnt+1, total-i-1, cnts, cur);
        }
    }
}

long long int dp(int x, int y, int z) {
    if (f[x][y][z] != -1) return f[x][y][z];

    if (x == z) return f[x][y][z] = 1;

    f[x][y][z] = 0;
    for (int i = 1; i < y; ++i) {
        f[x][y][z] += dp(x+1, y-i-1, z);
    }
    return f[x][y][z];
}

long long int calc(int N) {
    if (ans[N] != -1) return ans[N];

    ans[N] = 0;
    for (int k = 1; k <= N; ++k) {
        // ans[N] += C(N+1-k, k-1);
        ans[N] += dp(0, N, k);
    }
    return ans[N];
}

int main()
{
   // testin;
   // testout;

   // memset(ans, -1, sizeof(ans));
   // memset(f, -1, sizeof(f));

    while(cin >> n) {
        cout << ans[n] << endl;
    }

    return 0;
}
