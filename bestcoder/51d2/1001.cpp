// http://math.stackexchange.com/questions/307/prove-that-n-1-equiv-1-pmodn-iff-n-is-prime
//

# include <iostream>
using namespace std;

typedef long long int lli;

const lli maxn = 1e5+5;

bool isp[maxn];
int p[maxn], pc = 0;

void pre() {
    for (int i = 2; i < maxn; ++i) {
        if (!isp[i]) {
            p[pc++] = i;
            for (lli j = i; j*i < maxn; ++j) {
                isp[j*i] = true;
            }
        }
    }
}

int n;

int main()
{
    pre();
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        bool ok = true;
        for (int i = 0; i < pc && n > p[i]; ++i) {
            if (n%p[i] == 0) {
                ok = false;
                break;
            }
        }
        if (ok) cout << n-1;
        else cout << 0;
        cout << endl;
    }

    return 0;
}

