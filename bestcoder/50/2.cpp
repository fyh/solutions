# include <iostream>
# include <algorithm>
using namespace std;

const int maxn = 25;

int n;
int x[maxn], y[maxn];

int sq(int x) { return x * x; }

int d2(int i, int j) {
    return sq(x[i]-x[j]) + sq(y[i]-y[j]);
}

bool is3(int i, int j, int k) {
    return d2(i,j)==d2(j,k) && d2(j,k)==d2(i,k);
}

bool sa(int i, int j, int k, int p) {
    int a[4];
    a[0] = d2(i, j);
    a[1] = d2(i, k);
    a[2] = d2(i, p);
    sort(a, a+3);
    return a[0]==a[1] && a[2]==2*a[1];
}

bool is4(int i, int j, int k, int p) {
    return ( sa(i, j, k, p) &&
         sa(j, i, k, p) &&
         sa(k, i, j, p) &&
         sa(p, i, j, k) );
}

int main()
{
    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                for (int k = j+1; k < n; ++k) {
                    if (is3(i,j,k)) ++ans;
                    else for (int p = k+1; p < n; ++p) {
                        if (is4(i,j,k,p)) ++ans;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
