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

    ll N, W;
    cin >> N >> W;
    vll A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<pair<ll, ll>> C(N);
    rep(i, N) C[i] = {A[i], B[i]};
    sort(all(C), [](auto l, auto r){ return l.first>r.first; });

    ll ans = 0;
    rep(i, N){
        ll w = min(C[i].second, W);
        ans += w * C[i].first;
        W -= w;
        if(W==0) break;
    }
    cout << ans << endl;
}
