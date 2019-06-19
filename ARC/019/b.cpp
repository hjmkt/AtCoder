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

int main(){
    string s;
    cin >> s;
    ll count = 0;
    vll d;
    rep(i, s.length()/2){
        if(s[i]!=s[-i+s.length()-1]) d.push_back(i);
    }
    if(d.size()==0){
        count = 25 * (s.length()/2*2);
    }
    else if(d.size()!=1){
        count = 25 * s.length();
    }
    else{
        count = 25 * (s.length()-2) + 24*2;
    }
    cout << count << endl;
}
