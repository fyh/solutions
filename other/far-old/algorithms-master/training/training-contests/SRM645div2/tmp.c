#line 84 "ConnectingCars.cpp"
# include <string>
# include <vector>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
using namespace std;

# define testin freopen("in.txt", "r", stdin)
# define testout freopen("out.txt", "w", stdout)

# define rep(x) for(int i = 0; i < (x); ++i)
# define clr(x) memset(x, 0, sizeof(x))
# define clrc(x, c) memset(x, 0, (c)*sizeof(x[0]))

typedef unsigned long long int ulli;
typedef long long int lli;

class ConnectingCars {
	public:
	int Abs(int x) { return x<0 ? -x:x;}
	long long minimizeCost(vector <int> positions, vector <int> lengths) {
	    std::vector< pair<int, int> > vec;
	    int n = positions.size();
	    for (int i = 0; i < n; ++i) {
	        vec.push_back( make_pair(positions[i], lengths[i]) );
	    }
	    sort(vec.begin(), vec.end());
        long long int gaps[n];
        for (int i = 0; i+1 < n; ++i) gaps[i] = positions[i+1]-positions[i]-lengths[i];
        long long int ans = 0x7FFFFFFFFFFFFFFF;
        for (int i = 0; i < n; ++i) {
            long long int curs = 0;
            for (int j = 0; j+1 < n; ++j) {
                if (j >= i) cus += (n-1-j)*gaps[j];
                else curs += (j+1)*gaps[j];
            }
            ans = std::min( curs, ans );
        }
        return ans;
	}
};


// Powered by FileEdit
