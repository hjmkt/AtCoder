#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

vector<uset<ll>> scc(vector<uset<ll>>& e){
    ll n = e.size();
    vll labels(n, -1);
    vector<uset<ll>> s;
    ll count = 0;
    vector<bool> visited(n, false);
    function<ll(ll, ll)> dfs = [&](ll root, ll count){
        visited[root] = true;
        for(ll m: e[root]){
            if(visited[m]) continue;
            count = dfs(m, count) + 1;
        }
        return labels[root] = count;
    };
    rep(i, n){
        if(labels[i]>=0) continue;
        count = dfs(i, count) + 1;
    }
    map<ll, ll> t;
    rep(i, n) t[labels[i]] = i;
    ll scc_idx = 0;
    vector<bool> checked(n, false);
    vector<uset<ll>> ie(n);
    rep(i, n) for(ll m: e[i]) ie[m].insert(i);
    while(!t.empty()){
        uset<ll> c;
        auto [_, root] = *t.rbegin();
        deque<ll> q = {root};
        while(!q.empty()){
            ll m = q.front();
            q.pop_front();
            checked[m] = true;
            c.insert(m);
            t.erase(labels[root]);
            for(ll o: ie[m]){
                if(checked[o]) continue;
                checked[o] = true;
                q.push_back(o);
            }
        }
        s.push_back(c);
    }
    return s;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M;
    cin >> N >> M;
    vll A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    vector<uset<ll>> e(N);
    rep(i, M) e[A[i]-1].insert(B[i]-1);
    auto sccs = scc(e);

    ll ans = 0;
    for(auto& c: sccs){
        ll n = c.size();
        ans += n*(n-1) / 2;
    }
    cout << ans << endl;
}
