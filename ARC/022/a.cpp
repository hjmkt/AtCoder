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
    string ICT = "ICT";
    string ict = "ict";
    ll idx = 0;
    bool found = false;
    rep(i, s.length()){
        if(s[i]==ict[idx] || s[i]==ICT[idx]){
            ++idx;
            if(idx==3){
                found = true;
                break;
            }
        }
    }
    if(found) cout << "YES" << endl;
    else cout << "NO" << endl;
}
