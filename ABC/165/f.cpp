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

    ll N;
    cin >> N;
    vll a(N), u(N-1), v(N-1);
    rep(i, N) cin >> a[i];
    rep(i, N-1) cin >> u[i] >> v[i];
    vector<unordered_set<ll>> path(N);
    rep(i, N-1){
        path[u[i]-1].insert(v[i]-1);
        path[v[i]-1].insert(u[i]-1);
    }

    vll t(N+1, LLONG_MAX);
    vll res(N, 0);
    vll c(N, 0);

    function<void(ll)> solve = [&](ll idx){
        if(c[idx]) return;
        c[idx] = 1;
        auto it = lower_bound(all(t), a[idx]);
        ll tmp = *it;
        *it = min(*it, a[idx]);
        auto it2 = lower_bound(all(t), LLONG_MAX);
        ll nlis = distance(t.begin(), it2);
        res[idx] = nlis;
        for(ll next : path[idx]){
            solve(next);
        }
        *it = tmp;
    };
    solve(0);

    rep(i, N){
        cout << res[i] << endl;
    }
}
