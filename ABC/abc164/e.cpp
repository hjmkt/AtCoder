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

template<typename T=ll>
vector<ll> djkstra(vector<unordered_map<ll, T>> &e, ll src, function<bool(const T&, const T&)> comp=greater<T>()){
    auto c = [&comp](pair<T, ll> l, pair<T, ll> r){ return comp(l.first, r.first); };
    priority_queue<pair<T, ll>, vector<pair<T, ll>>, decltype(c)> q(c);
    vector<T> s(e.size(), LLONG_MAX);
    q.push({0, src});
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        ll d = p.first;
        ll n = p.second;
        if(s[n]<LLONG_MAX) continue;
        s[n] = d;
        for(auto t : e[n]){
            if(s[t.first]<LLONG_MAX) continue;
            q.push({d+t.second, t.first});
        }
    }
    return s;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M, S;
    cin >> N >> M >> S;
    vll U(M), V(M), A(M), B(M);
    vll C(N), D(N);
    rep(i, M) cin >> U[i] >> V[i] >> A[i] >> B[i];
    rep(i, N) cin >> C[i] >> D[i];

    vector<unordered_map<ll, ll>> e(N*2500, unordered_map<ll, ll>());
    rep(i, M) rep(j, 2500){
        if(j-A[i]>=0){
            e[2500*(U[i]-1)+j][2500*(V[i]-1)+j-A[i]] = B[i];
            e[2500*(V[i]-1)+j][2500*(U[i]-1)+j-A[i]] = B[i];
        }
    }
    rep(i, N) rep(j, 2500) e[2500*i+j][2500*i+min(j+C[i], 2499ll)] = D[i];

    auto s = djkstra(e, min(S, 2499ll));
    REP(i, 1, N) cout << *min_element(s.begin()+i*2500, s.begin()+(i+1)*2500) << endl;
}
