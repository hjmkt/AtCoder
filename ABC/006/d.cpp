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
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;
    vll c(N);
    rep(i, N) cin >> c[i];

    vll dp(N+1, LLONG_MAX);
    rep(i, N){
        auto it = lower_bound(all(dp), c[i]);
        *it = min(*it, c[i]);
    }
    auto it = lower_bound(all(dp), LLONG_MAX);
    ll nlis = distance(dp.begin(), it);
    cout << (N-nlis) << endl;
}
