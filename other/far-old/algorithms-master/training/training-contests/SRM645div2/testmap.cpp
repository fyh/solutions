# include <map>
# include <iostream>
using namespace std;

typedef long long int lli;

int main()
{
    map<lli, double> mem;

    mem.clear();

    lli a = 0x123456789;
    mem[a] = 3.1415;

    cout << mem.find(a)->second << endl;
    cout << mem.find(a)->first << endl;

    lli b = 0x1234567912;

    if ( mem.find(b) != mem.end() ) {
        cout << "find" << endl;
    } else {
        cout << "non-exist" << endl;
    }

    cout << mem.find(b)->second << endl;
    cout << mem.find(b)->first << endl;

    cout << mem.end()->first << endl;
    cout << mem.end()->second << endl;

    return 0;
}
