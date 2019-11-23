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
    cout << setprecision(20);
    ll n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    ll s = 0;
    rep(i, n) s += a[i];
    ll t = 0;
    rep(i, n){
        ll nt = t+a[i];
        if(nt>s/2){
            ll c = min(s-2*t, 2*nt-s);
            cout << c << endl;
            return 0;
        }
        t = nt;
    }
}
