# include <map>
# include <set>
using namespace std;
class Solution {
private:
    map<int, int> m;
    set<int> s;
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
	    m.clear();
	    for (int i = 0; i < length; ++i) {
            int t = numbers[i];
            if (!m[t]) {
                ++m[t];
            } else {
                s.insert(t);
            }
	    }
	    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
            *duplication = *it;
            ++duplication;
	    }
	    return !s.empty();
	}
};
