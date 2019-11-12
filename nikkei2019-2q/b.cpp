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
    vll d(n);
    rep(i, n) cin >> d[i];

    if(d[0]!=0) cout << 0 << endl;
    else{
        sort(all(d));
        ll m = d[d.size()-1];
        vll c(m+1, 0);
        rep(i, n) ++c[d[i]];
        if(c[0]>1) cout << 0 << endl;
        else{
            ll a = 1;
            REP(i, 1, c.size()){
                if(c[i]==0){
                    cout << 0 << endl;
                    return 0;
                }
                rep(j, c[i]) a = a*c[i-1]%998244353;
            }
            cout << a << endl;
        }
    }
}
