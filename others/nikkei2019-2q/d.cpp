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

template<typename T=ll>
ll djkstra(vector<map<ll, T>> &g, ll src, ll dst, function<bool(const T&, const T&)> comp=greater<T>()){
    auto c = [&comp](pair<T, ll> l, pair<T, ll> r){ return comp(l.first, r.first); };
    priority_queue<pair<T, ll>, vector<pair<T, ll>>, decltype(c)> q(c);
    vector<T> s(g.size(), -1);
    q.push({0, src});
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        ll d = e.first;
        ll n = e.second;
        if(s[n]>=0) continue;
        s[n] = d;
        if(n==dst) break;
        for(auto it=g[n].begin(); it!=g[n].end(); ++it){
            if(s[it->first]>=0 || it->second<0) continue;
            q.push({d+it->second, it->first});
        }
    }
    return s[dst];
}

int main(){
    ll n, m;
    cin >> n >> m;
    vector<map<ll, ll>> lrc(n);
    rep(i, m){
        ll l, r, c;
        cin >> l >> r >> c;
        if(lrc[l-1].find(r-1) != lrc[l-1].end()){
            lrc[l-1][r-1] = min(lrc[l-1][r-1], c);
        }
        else lrc[l-1][r-1] = c;
    }
    rep(i, n-1) lrc[i+1][i] = 0;
    
    ll a = djkstra(lrc, 0, n-1);
    cout << a << endl;
}
