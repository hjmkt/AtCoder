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
void warshall(vector<vector<T>> &v, function<bool(const T&, const T&)> comp=less<T>()){
    ll n = v.size();
    rep(i, n) rep(j, n) rep(k, n){
        v[j][k] = comp(v[j][k], v[j][i]+v[i][k])? v[j][k] : (v[j][i]+v[i][k]);
    }
}

int main(){
    ll n, m, l;
    cin >> n >> m >> l;
    vvll d(n, vll(n, INT_MAX));
    rep(i, n) d[i][i] = 0;
    rep(i, m){
        ll a, b, c;
        cin >> a >> b >> c;
        d[a-1][b-1] = d[b-1][a-1] = c;
    }
    ll q;
    cin >> q;
    vll s(q), t(q);
    rep(i, q) cin >> s[i] >> t[i];

    warshall(d);
    rep(i, n) rep(j, n){
        d[i][j] = i==j? 0 : d[i][j]<=l? 1 : INT_MAX;
    }
    warshall(d);

    rep(i, q){
        ll res = d[s[i]-1][t[i]-1];
        cout << (res<INT_MAX? (res-1) : -1) << endl;
    }
}
