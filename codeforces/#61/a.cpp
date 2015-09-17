# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

char s[105];

int main()
{
    cin >> s;
    int n = strlen(s);
    if (n < 3 || (n==3 && strcmp(s,"127")<=0)) cout << "byte";
    else if (n < 5 || (n==5 && strcmp(s, "32767")<=0)) cout << "short";
    else if (n < 10 || (n==10 && strcmp(s, "2147483647")<=0)) cout << "int";
    else if (n < strlen("9223372036854775807") || (n==strlen("9223372036854775807") && strcmp(s, "9223372036854775807")<=0)) cout << "long";
    else cout << "BigInteger";
    cout << endl;

    return 0;
}
