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
    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vll ta(a), tb(b);
    sort(all(ta), greater<ll>());
    sort(all(tb), greater<ll>());
    ll last = LONG_MAX;
    bool rep = false;
    rep(i, n){
        if(ta[i]>tb[i]){
            cout << "No" << endl;
            return 0;
        }
        if(last<=tb[i]) rep = true;
        last = ta[i];
    }
    if(rep) cout << "Yes" << endl;
    else{
        unordered_map<ll, ll> m, om, im, oim;
        rep(i, n) m.insert({ta[i], tb[i]});
        rep(i, n) im.insert({tb[i], ta[i]});
        rep(i, n) om.insert({a[i], b[i]});
        rep(i, n) oim.insert({b[i], a[i]});
        rep(i, n){
            if(i<n-1 && m[a[i]]==om[a[i]]){
                cout << "Yes" << endl;
                return 0;
            }
            ll a1 = a[i];
            ll b1 = m[a1];
            ll a2 = oim[m[a1]];
            ll b2 = om[a1];
            om[a1] = b1;
            om[a2] = b2;
            oim[b1] = a1;
            oim[b2] = a2;
        }
        cout << "No" << endl;
    }
}
