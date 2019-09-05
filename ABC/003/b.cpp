#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()

bool atcoder(char c){
    return c=='a' || c=='t' || c=='c' || c=='o' || c=='d' || c=='e' || c=='r';
}

int main(){
    string s, t;
    cin >> s >> t;

    rep(i, s.length()){
        if(s[i]!=t[i] && !((s[i]=='@' && atcoder(t[i]) || (atcoder(s[i]) && t[i]=='@')))){
            cout << "You will lose" << endl;
            return 0;
        }
    }
    cout << "You can win" << endl;
}
