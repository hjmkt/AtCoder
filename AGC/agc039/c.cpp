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
    string x;
    cin >> x;

    ll t = 2*n;
    ll res = 2*n;
    rep(i, n){
        ll b = x[x.length()-1-i] - '0';
        res = (res+t*b) % 998244353;
        t = t*2 % 998244353;
    }
    REP(r, 1, n/2+2){
        if(n%(2*r)==r){
            ll lb = 0;
            ll acc = 0;
            rep(i, n){
                ll cb = x[i] - '0';
                if(lb>cb) break;
                if(lb<cb){
                    res = (res-2*n+2*r+998244353) % 998244353;
                    break;
                }
                if(lb==cb && i==n-1) res = (res-2*n+2*r+998244353) % 998244353;
                if(acc%r==0){
                    lb = 1 - lb;
                }
                ++acc;
            }
            lb = 1;
            acc = 0;
            rep(i, n){
                ll cb = x[i] - '0';
                if(lb>cb) break;
                if(lb<cb){
                    res = (res-2*n+2*r+998244353) % 998244353;
                    break;
                }
                if(lb==cb && i==n-1) res = (res-2*n+2*r+998244353) % 998244353;
                if(acc%r==0){
                    lb = 1 - lb;
                }
                ++acc;
            }
        }
    }
    cout << res << endl;
}
