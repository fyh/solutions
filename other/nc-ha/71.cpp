# include <iostream>
# include <string>
# include <map>
# include <stdio.h>

int n;

const int maxn = 1055;

std::string str;
std::map<std::string, int> mp;

char getCh(char ch) {
    if ('A'<=ch && ch<='C') return 2;
    if ('D'<=ch && ch<='F') return 3;
    if ('G'<=ch && ch<='I') return 4;
    if ('J'<=ch && ch<='L') return 5;
    if ('M'<=ch && ch<='O') return 6;
    if ('P'<=ch && ch<='S') return 7;
    if ('T'<=ch && ch<='V') return 8;
    if ('W'<=ch && ch<='Z') return 9;
}

std::string get(std::string &s) {
    std::string r(8, '0');
    for (int i = 0, j = 0; i < s.length(); ++i) {
        if (isalpha(s[i]) || isdigit(s[i])) {
            if (isdigit(s[i])) r[j] = s[i];
            else r[j] = getCh(s[i])+'0';
            ++j;
            if (j == 3) r[j++] = '-';
        }
    }
    return r;
}

int main()
{
    while (~scanf("%d", &n)) {
        mp.clear();
        for (int i = 0; i < n; ++i) {
            std::cin >> str;
            ++mp[get(str)];
        }
        for (std::map<std::string, int>::iterator it = mp.begin();
            it != mp.end();
            ++it) {
            std::cout << it->first << std::endl;
        }
        puts("");
    }

    return 0;
}
