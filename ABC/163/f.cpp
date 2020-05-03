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
    vll a(N-1), b(N-1), c(N);
    rep(i, N){
        cin >> c[i];
        --c[i];
    }
    rep(i, N-1) cin >> a[i] >> b[i];
    vector<unordered_set<ll>> e(N);
    rep(i, N-1){
        e[a[i]-1].insert(b[i]-1);
        e[b[i]-1].insert(a[i]-1);
    }

    vll t(N, 0), cnt(N, 0);

    function<ll(ll, ll)> dfs = [&](ll cur, ll prev){
        ll count = 1;
        ll color = c[cur];
        ll tmp = cnt[color];
        for(ll next : e[cur]){
            if(next==prev) continue;
            ll bfr = cnt[color];
            ll num = dfs(next, cur);
            count += num;
            ll aftr = cnt[color];
            ll sub = aftr - bfr;
            ll diff = num - sub;
            t[color] += diff*(diff+1)/2;
        }
        cnt[color] = tmp + count;
        return count;
    };
    dfs(0, -1);

    ll w = N*(N+1)/2;
    rep(i, N){
        ll r = N - cnt[i];
        ll a = t[i] + r*(r+1)/2;
        cout << (w-a) << endl;
    }
}
