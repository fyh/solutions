# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

char *sn[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H", "0"};

char s[3][5];

int get(int x, int i) {
    for (; sn[x][0] != '0'; ++x) {
        if (strcmp(sn[x], s[i]) == 0) return x;
    }
    return -1;
}

bool check(int x, int y, int z, int p, int q) {
    int a = get(0, x);
    int b = get(a+1, y);
    int c = get(b+1, z);
    return a+p==b && b+q==c;
}

int main()
{
    for (int i = 0; i < 3; ++i) cin >> s[i];

    if (check(0,1,2,4,3) || check(1,2,0,4,3) || check(2,0,1,4,3) ||
        check(0,2,1,4,3) || check(1,0,2,4,3) || check(2,1,0,4,3)) {
        cout << "major";
    } else if (check(0,1,2,3,4) || check(1,2,0,3,4) || check(2,0,1,3,4) ||
               check(0,2,1,3,4) || check(1,0,2,3,4) || check(2,1,0,3,4)) {
        cout << "minor";
    } else cout << "strange";
    cout << endl;

    return 0;
}
