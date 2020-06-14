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


template<typename A, typename B>
struct pair_hash{
    inline size_t operator()(const pair<A, B> &p) const{
        const auto h1 = hash<A>()(p.first);
        const auto h2 = hash<B>()(p.second);
        return h1^(h2<<18);
    }
};


template<typename T=ll>
vector<ll> djkstra(vector<vector<T>> &v, ll src, function<bool(const T&, const T&)> comp=greater<T>()){
    auto c = [&comp](pair<T, ll> l, pair<T, ll> r){ return comp(l.first, r.first); };
    priority_queue<pair<T, ll>, vector<pair<T, ll>>, decltype(c)> q(c);
    vector<T> s(v.size(), LLONG_MAX);
    q.push({0, src});
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        ll d = e.first;
        ll n = e.second;
        if(s[n]<LLONG_MAX) continue;
        s[n] = d;
        rep(i, v.size()){
            if(s[i]<LLONG_MAX || v[n][i]<0) continue;
            q.push({d+v[n][i], i});
        }
    }
    return s;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll H, W, K;
    cin >> H >> W >> K;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<string> c(H);
    rep(i, H) cin >> c[i];
}
