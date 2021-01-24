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

    ll ans = 0;
    rep(l, N){
        ll s = 0;
        ll m = A[l];
        REP(r, l, N){
            m = min(m, A[r]);
            ll t = m*(r-l+1);
            s = max(s, t);
        }
        ans = max(s, ans);
    }
    cout << ans << endl;
}
