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
    vll d(n);
    rep(i, n) cin >> d[i];

    ll s = 0, ss = 0;
    rep(i, n){
        s += d[i];
        ss += d[i]*d[i];
    }
    ll res = (s*s-ss) / 2;
    cout << res << endl;
}
