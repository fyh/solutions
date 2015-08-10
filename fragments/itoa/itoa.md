
```
# include <iostream>
# include <vector>
# include <numeric>
# include <iterator>
using namespace std;

int main()
{
	vector<int> V(10);
	iota(V.begin(), V.end(), 7);
	copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
	return 0;
}
```

[1]:http://www.sgi.com/tech/stl/iota.html
[2]:http://stackoverflow.com/questions/14426366/what-is-an-idiomatic-way-of-representing-enums-in-golang
[3]:http://www.cplusplus.com/reference/iterator/ostream_iterator/
