# include <iostream>
# include <cstring>
int f[256];
void prebuild(void)
{
    memset(f, 0, sizeof(f));
    f['A'] = 'A';
    f['E'] = '3';
    f['H'] = 'H';
    f['I'] = 'I';
    f['J'] = 'L';
    f['L'] = 'J';
    f['M'] = 'M';
    f['O'] = 'O';
    f['S'] = '2';
    f['T'] = 'T';
    f['U'] = 'U';
    f['V'] = 'V';
    f['W'] = 'W';
    f['X'] = 'X';
    f['Y'] = 'Y';
    f['Z'] = '5';
    f['1'] = '1';
    f['2'] = 'S';
    f['3'] = 'E';
    f['5'] = 'S';
    f['8'] = '8';
}
bool isParlindrome(char *str)
{
    int n = strlen(str);
    for (int i = 0; str[i]; ++i) {
        if (str[i] != str[n-1-i]) return false;
    }
    return true;
}
bool isMirriored(char *str)
{
    int n = strlen(str);
    for (int i = 0; str[i]; ++i) {
        if (str[i] != f[ str[n-1-i] ]) return false;
    }
    return true;
}

char s[25];
int main()
{
    prebuild();
    while (std::cin >> s) {
        bool isP = isParlindrome(s);
        bool isM = isMirriored(s);
        if (isP && isM) std::cout << s << " -- is a mirrored palindrome." ;
        if (isP && !isM) std::cout << s << " -- is a regular palindrome.";
        if (!isP && isM) std::cout << s << " -- is a mirrored string.";
        if (!isP && !isM) std::cout << s << " -- is not a palindrome.";
        std::cout << std::endl << std::endl;
    }

    return 0;
}
