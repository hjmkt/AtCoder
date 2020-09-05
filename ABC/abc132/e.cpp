#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    ll N, M;
    cin >> N >> M;
    if(M==0){
        cout << -1 << endl;
        return 0;
    }
    vll u(M), v(M);
    rep(i, M){
        cin >> u[i] >> v[i];
    }
    ll S, T;
    cin >> S >> T;
    vector<unordered_set<ll>> m(3*N+3);
    rep(i, M){
        m[3*u[i]-3].insert(3*v[i]-2);
        m[3*u[i]-2].insert(3*v[i]-1);
        m[3*u[i]-1].insert(3*v[i]-3);
    }
    auto c = [](pair<ll, ll> l, pair<ll, ll> r){ return l.first>r.first; };
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(c)> q(c);
    vll s(3*N+3, -1);
    q.push({0, 3*S-3});
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        ll n = e.second;
        ll d = e.first;
        if(s[n]>=0) continue;
        s[n] = d;
        for(ll a : m[n]){
            if(s[a]==-1){
                q.push({d+1, a});
            }
        }
    }
    if(s[T*3-3]<0) cout << -1 << endl;
    else cout << (s[T*3-3]/3) << endl;
}
