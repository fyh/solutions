// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Given a set S of points in the plane we can generate a new set T in the following fashion:

 1) For all distinct points p and q in S, the midpoint of the line segment from p to q should be added to T.
 2) Remove all duplicate points in T so that there is only one copy of each point in T.

The process used to convert S into T is called a round.

You will be given vector <int>s xs and ys denoting the points contained in S.  Point i will have x-coordinate xs[i] and y-coordinate ys[i].  After applying rnds rounds to S, you will return the best point.  One point is better than another if it has a larger y-coordinate.  In case of a tie, the point with the larger x-coordinate is then better.  The returned point should have the form (quotes for clarity) "x y" where x and y denote the x and y coordinates respectively.  Each coordinate has the format (quotes for clarity) "####.####".  In other words, there should be exactly 4 digits before the decimal place and 4 digits afterward.  When necessary, round down to the nearest ten-thousandth.

DEFINITION
Class:PointLifeGame
Method:simulate
Parameters:vector <int>, vector <int>, int
Returns:string
Method signature:string simulate(vector <int> xs, vector <int> ys, int rnds)


CONSTRAINTS
-xs must contain between 3 and 50 elements inclusive.
-ys must contain the same number of elements as xs.
-Each element of xs will be between 0 and 5000 inclusive.
-Each element of ys will be between 0 and 5000 inclusive.
-rnds must be between 1 and 10 inclusive.
-Each given point will be distinct.


EXAMPLES

0)
{0,0,10,10}
{0,10,0,10}
1

Returns: "0005.0000 0010.0000"

The given points are arranged in a 10 by 10 square.  After 1 round the best point lies on the middle of the top edge of the original square.

1)
{0,0,10,10}
{0,10,0,10}
10

Returns: "0005.0097 0007.5000"

Same as before, but now there are 10 rounds.

2)
{0,10,20}
{0,10,0}
1

Returns: "0015.0000 0005.0000"

Here we have a triangular arrangement.  After 1 round the best point lies on the upper right edge of the original triangle.

3)
{1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10}
{1,1,1,1,1,1,1,1,1,1,
 2,2,2,2,2,2,2,2,2,2,
 3,3,3,3,3,3,3,3,3,3,
 4,4,4,4,4,4,4,4,4,4,
 5,5,5,5,5,5,5,5,5,5}
10

Returns: "0009.0009 0005.0000"

4)
{3,3,8,0}
{2,1,1,3}
10

Returns: "0002.4658 0002.1875"

*/
// END CUT HERE
#line 84 "PointLifeGame.cpp"
#include<bits/stdc++.h>
using namespace std;

struct point{
    double x, y;
    point(double _x, double _y):x(_x), y(_y) {}
    void P() {
        cout << x << ", " << y << endl;
    }
};

struct cmp {
    bool operator()(const point &a, const point &b) {
        if (a.y == b.y) return a.x >= b.x;
        return a.y >= b.y;
    }
};

class PointLifeGame {
	public:
	string simulate(vector <int> xs, vector <int> ys, int rnds) {
	    priority_queue<point, vector<point>, cmp> Q;
	    for (int i = 0; i < xs.size(); ++i) {
            Q.push(point(xs[i]*1.0, ys[i]*1.0));
	    }
	    vector<point> mid;
	    for (int i = rnds; i > 0; --i) {
            while (Q.size() > i+1) Q.pop();
            mid.clear();
            while (Q.size()) {
                mid.push_back(Q.top());
                point t = Q.top(); t.P();
                Q.pop();
            }
            for (int i = 0; i < mid.size(); ++i) {
                for (int j = i+1; j < mid.size(); ++j) {
                    Q.push(point(0.5*(mid[i].x+mid[j].x), 0.5*(mid[i].y+mid[j].y)));
                }
            }
	    }
	    point las(0, 0);
	    while (Q.size()) {
            if (Q.size() == 1) las = Q.top();
            Q.pop();
	    }
	    string ret;
	    char t[25];
	    printf("%04d%.4lf %04d%.4lf", (int)las.x, las.x-(int)las.x, las.y-(int)las.y);
	    sprintf(t, "%04d%.4lf %04d%.4lf", (int)las.x, las.x-(int)las.x, las.y-(int)las.y);
	    cout << t << endl;
	    cout << string(t) << endl;
	    return string(t);
	}
};

