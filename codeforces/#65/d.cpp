# include <bits/stdc++.h>
using namespace std;

int n, m;

char* s = "CDHS";
char* r = "23456789TJQKA";

typedef pair<char,char> pcc;
typedef pair<int,int> pii;

set<pcc> S;
vector<pii> T;

pcc arr[20][20];
vector<pii> ans;
char *arr2[] = {"first", "second"};

bool ins(pii a, pii b) {
    if( !(a.first<=b.first&&b.first<=a.first+2 && a.second<=b.second&&b.second<=a.second+2) )return false;
    if( !(b.first<=a.first&&a.first<=b.first+2 && b.second<=a.second&&a.second<=b.second+2) )return false;
    return true;
}

bool ok(int i, int j) {
    for (int k = 0; k < ans.size(); ++i) {
        if (ins(make_pair(i,j), ans[k])) return false;
    }
    map<int, int> M;
    bool a = true, b = false;
    for (int p = 0; p < 3; ++p) {
        for (int q = 0; q < 3; ++q) {
            if (M.count(arr[p+i][q+j].first)) a = false;
            else M[arr[p+i][q+j].first] = 1;
            if (arr[p+i][q+j].second != arr[i][j].second) b = false;
            if (!a && !b) return false;
        }
    }
    return (a || b);
}

bool chk() {
    int cnt = 0;
    for (int i = 1; i+3 <= n+1 ; ++i) {
        for (int j = 1; j+3 <= m+1; ++j) {
            if (ok(i,j)) {
                ans.push_back(make_pair(i,j));
                ++cnt;
                if (cnt >= 2) return true;
            }
        }
    }
    ans.clear();
    return false;
}

void output() {
    for (int i = 0; i < ans.size(); ++i) {
        cout << "Put the "<< arr2[i] << " square to (" << ans[i].first << ", " << ans[i].second << ")." << endl;
    }
}

int main()
{
    for (int i = 0; r[i]; ++i) {
        for (int j = 0; s[j]; ++j) {
            S.insert( make_pair(r[i], s[j]) );
        }
    }
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char str[5]; cin >> str;
            arr[i][j] = make_pair(str[0], str[1]);
            S.erase(arr[i][j]);
            if (str[0] == 'J') {
                T.push_back(make_pair(i,j));
            }
        }
    }

    if (T.size() == 2 && T[0].second=='2' )  swap(T[0], T[1]);

    if (T.empty()) {
        if (chk()) {
            cout << "Solution exists." << endl << "There are no jokers." << endl;
            return 0;
        }
    } else if (T.size() == 1) {
        int tmp = arr[ T[0].first ][ T[0].second ].second - '0';
        for (auto it = S.begin(); !ok && it != S.end(); ++it) {
            arr[ T[0].first ][ T[0].second ] = *it;
            if (chk()) {
                cout << "Solution exists." << endl;
                cout << "Replace J" << tmp << " with " << it->first << it->second << "." << endl;
                output();
                return 0;
            }
        }
    } else {
        for (auto it = S.begin(); !ok && it != S.end(); ++it) {
            for (auto it2 = S.begin(); !ok && it2 != S.end(); ++it2) if (it != it2) {
                arr[ T[0].first ][ T[0].second ] = *it;
                arr[ T[1].first ][ T[1].second ] = *it2;
                if (chk()) {
                    cout << "Solution exists." << endl;
                    cout << "Replace J1 with " << it->first << it->second << " and J2 with " << it2->first << it2->second  << "." << endl;
                    output();
                    return 0;
                }
            }
        }
    }
    cout << "No solution." << endl;

    return 0;
}
