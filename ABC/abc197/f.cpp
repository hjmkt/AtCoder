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
    vector<char> C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];


}
