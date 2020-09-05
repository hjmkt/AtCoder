#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    string s;
    cin >> s;
    if(s[0]==s[1] || s[1]==s[2] || s[2]==s[3]){
        cout << "Bad" << endl;
    }
    else cout << "Good" << endl;
}
