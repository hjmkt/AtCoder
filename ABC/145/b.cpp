#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;

    if(s.length()%2!=0) cout << "No" << endl;
    else{
        string s0 = s.substr(0, s.length()/2);
        string s1 = s.substr(s.length()/2);
        if(s0==s1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
