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
    vll A(N-1), B(N-1);
    rep(i, N-1) cin >> A[i] >> B[i];
    vector<set<ll>> e(N+1);
    rep(i, N-1){
        e[A[i]].insert(B[i]);
        e[B[i]].insert(A[i]);
    }

    function<pair<ll, ll>(ll, ll)> solve = [&](ll n, ll p){
        ll m = 0;
        ll t = n;
        for(ll c : e[n]){
            if(c==p) continue;
            auto r = solve(c, n);
            if(r.first+1>m){
                m = r.first+1;
                t = r.second;
            }
        }
        return pair<ll, ll>{m, t};
    };
    auto p = solve(1, 0);
    auto q = solve(p.second, 0);
    cout << q.first+1 << endl;
}
