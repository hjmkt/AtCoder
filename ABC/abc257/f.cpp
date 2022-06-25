#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;
template<class T> using mset = multiset<T>;
template<class T, class U> using mmap = multimap<T, U>;
template<class T> using umset = unordered_multiset<T>;
template<class T, class U> using ummap = unordered_multimap<T, U>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

template<typename T=ll>
pair<vector<ll>, vector<ll>> djkstra(vector<unordered_map<ll, T>> &e, ll src, function<bool(const T&, const T&)> comp=greater<T>()){
    auto c = [&comp](tuple<T, ll, ll> l, tuple<T, ll, ll> r){ return comp(get<0>(l), get<0>(r)); };
    priority_queue<tuple<T, ll, ll>, vector<tuple<T, ll, ll>>, decltype(c)> q(c);
    vector<T> s(e.size(), LLONG_MAX);
    vector<ll> prev(e.size(), -1);
    q.push({0, src, -1});
    while(!q.empty()){
        auto [d, n, p] = q.top();
        q.pop();
        if(s[n]<LLONG_MAX) continue;
        s[n] = d;
        prev[n] = p;
        for(auto t : e[n]){
            if(s[t.first]<LLONG_MAX) continue;
            q.push({d+t.second, t.first, n});
        }
    }
    return {s, prev};
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M;
    cin >> N >> M;
    vll U(M), V(M);
    rep(i, M) cin >> U[i] >> V[i];

    vector<umap<ll, ll>> g(N);
    rep(i, M){
        if(U[i]>0 && V[i]>0){
            g[U[i]-1][V[i]-1] = g[V[i]-1][U[i]-1] = 1;
        }
    }
    auto [from1, _1] = djkstra(g, 0);
    auto [fromN, _2] = djkstra(g, N-1);
    rep(i, N){
        if(from1[i]==LLONG_MAX) from1[i] = INT_MAX;
        if(fromN[i]==LLONG_MAX) fromN[i] = INT_MAX;
    }
    ll shortest_warp1 = INT_MAX, shortest_warpN = INT_MAX;
    rep(i, M){
        if(U[i]==0){
            shortest_warp1 = min(shortest_warp1, from1[V[i]-1]);
            shortest_warpN = min(shortest_warpN, fromN[V[i]-1]);
        }
        else if(V[i]==0){
            shortest_warp1 = min(shortest_warp1, from1[U[i]-1]);
            shortest_warpN = min(shortest_warpN, fromN[U[i]-1]);
        }
    }
    vll ans(N);
    rep(i, N){
        ll d = from1[N-1];
        d = min(d, from1[i]+1+shortest_warpN);
        d = min(d, fromN[i]+1+shortest_warp1);
        d = min(d, shortest_warp1+2+shortest_warpN);
        ans[i] = (d<INT_MAX? d : -1);
    }
    rep(i, N-1) cout << ans[i] << " ";
    cout << ans.back() << endl;
}
