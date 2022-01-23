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
    vvll A(2*N, vll(2*N));
    rep(i, 2*N-1){
        REP(j, i+1, 2*N){
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }
    function<ll(set<ll>, vector<pair<ll, ll>>)> solve = [&](set<ll> s, vector<pair<ll, ll>> p){
        if(s.empty()){
            ll t = 0;
            rep(i, N){
                t ^= A[p[i].first][p[i].second];
            }
            return t;
        }
        vll v(all(s));
        ll n = v.size();
        ll m = 0;
        s.erase(v[0]);
        rep(i, n-1){
            s.erase(v[i+1]);
            p.push_back({v[0], v[i+1]});
            ll t = solve(s, p);
            m = max(m, t);
            s.insert(v[i+1]);
            p.pop_back();
        }
        return m;
    };
    set<ll> s;
    rep(i, 2*N) s.insert(i);
    ll ans = solve(s, {});
    cout << ans << endl;
}
