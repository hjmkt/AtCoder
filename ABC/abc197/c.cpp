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
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    function<ll(vll, ll)> solve = [&](vll a, ll p){
        if(a.size()==0) return p;
        ll t = LLONG_MAX;
        ll r = 0;
        rep(i, a.size()){
            ll s = 0;
            rep(j, i+1) s |= a[j];
            ll tmp = solve(vll(a.begin()+(i+1), a.end()), p^s);
            t = min(t, tmp);
        }
        return t;
    };
    cout << solve(A, 0ll) << endl;
}
