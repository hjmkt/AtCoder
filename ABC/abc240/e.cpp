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
    vll u(N-1), v(N-1);
    rep(i, N-1) cin >> u[i] >> v[i];

    vector<unordered_set<ll>> t(N);
    rep(i, N-1){
        t[u[i]-1].insert(v[i]-1);
        t[v[i]-1].insert(u[i]-1);
    }

    vector<pair<ll, ll>> ans(N);

    function<pair<ll, ll>(ll, ll, ll)> solve = [&](ll cur, ll prev, ll m){
        if(cur!=0 && t[cur].size()==1){
            ans[cur] = {m+1, m+1};
            return ans[cur];
        }
        ll left = 0;
        ll count = 0;
        for(ll child: t[cur]){
            if(child==prev) continue;
            auto p = solve(child, cur, m);
            if(count==0){
                left = p.first;
            }
            m = p.second;
            ++count;
        }
        ll right = m;
        ans[cur] = {left, right};
        return ans[cur];
    };
    solve(0, -1, -1);
    rep(i, N){
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
}
