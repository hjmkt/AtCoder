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
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll c1[3] = {};
    ll c2[3] = {};

    ll total = 1;
    ll r = n;

    rep(i, s.length()){
        ll idx = s[i]=='R'? 0 : s[i]=='G'? 1 : 2;
        if(c2[idx]>0){
            total = total * c2[idx] % 998244353;
            total = total * r % 998244353;
            --c2[idx];
            --r;
        }
        else if(c1[(idx+1)%3]>0){
            total = total * c1[(idx+1)%3] % 998244353;
            --c1[(idx+1)%3];
            ++c2[(idx+2)%3];
        }
        else if(c1[(idx+2)%3]>0){
            total = total * c1[(idx+2)%3] % 998244353;
            --c1[(idx+2)%3];
            ++c2[(idx+1)%3];
        }
        else ++c1[idx];
    }
    cout << total << endl;
}
