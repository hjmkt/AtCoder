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
    vll x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    rep(i, N){
        ll tmp = x[i];
        x[i] = x[i] + y[i];
        y[i] = tmp - y[i];
    }
    ll ans = max(*max_element(all(x))-*min_element(all(x)), *max_element(all(y))-*min_element(all(y)));
    cout << ans << endl;
}
