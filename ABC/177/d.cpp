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
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M;
    cin >> N >> M;
    vll A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    vll p(N+1);
    rep(i, N+1) p[i] = i;
    
    function<ll(ll)> root = [&](ll x){
        if(p[x]==x) return x;
        return p[x] = root(p[x]);
    };

    rep(i, M){
        ll ra = root(A[i]);
        ll rb = root(B[i]);
        if(ra==rb) continue;
        p[ra] = rb;
    }

    vll cnts(N+1, 0);
    rep(i, N+1) ++cnts[root(i)];
    ll ans = *max_element(all(cnts));
    cout << ans << endl;
}
