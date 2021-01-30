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
    vll A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];
    ll K;
    cin >> K;
    vll C(K);
    rep(i, K) cin >> C[i];

    vector<unordered_map<ll, ll>> g(N);
    rep(i, M){
        g[A[i]-1][B[i]-1] = 1;
        g[B[i]-1][A[i]-1] = 1;
    }

    vvll d(K, vll(K, LLONG_MAX));
    rep(i, K){
        ll s = C[i] - 1;
        auto p = djkstra(g, s);
        REP(j, i+1, K){
            ll t = C[j] - 1;
            d[i][j] = d[j][i] = p.first[t];
        }
    }

    vvll dp(1<<K, vll(K, LLONG_MAX));
    rep(i, K) dp[0][i] = 0;
    REP(s, 1, 1<<K){
        rep(i, K){
            if((s>>i)&1) continue;
            rep(j, K){
                if((s>>j)&1){
                    ll t = s ^ (1<<j);
                    if(i!=j && d[i][j]<LLONG_MAX && dp[t][j]<LLONG_MAX){
                        dp[s][i] = min(dp[s][i], dp[t][j]+d[i][j]);
                    }
                }
            }
        }
    }

    ll ans = LLONG_MAX;
    rep(i, K){
        ans = min(ans, dp[((1<<K)-1)^(1<<i)][i]);
    }

    if(ans==LLONG_MAX) cout << -1 << endl;
    else cout << (ans+1) << endl;
}
