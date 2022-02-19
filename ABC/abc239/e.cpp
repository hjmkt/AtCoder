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

    ll N, Q;
    cin >> N >> Q;
    vll X(N), A(N-1), B(N-1), V(Q), K(Q);
    rep(i, N) cin >> X[i];
    rep(i, N-1) cin >> A[i] >> B[i];
    rep(i, Q) cin >> V[i] >> K[i];

    vector<set<ll>> t(N);
    rep(i, N-1){
        t[A[i]-1].insert(B[i] - 1);
        t[B[i]-1].insert(A[i] - 1);
    }

    vvll tops(N);
    function<vll(ll cur, ll prev)> solve = [&](ll cur, ll prev){
        if(cur!=0 && t[cur].size()==1){
            vll v{X[cur]};
            tops[cur].push_back(X[cur]);
            return v;
        }
        vll v{X[cur]};
        for(ll child : t[cur]){
            if(child==prev) continue;
            vll t = solve(child, cur);
            for(ll n: t){
                v.push_back(n);
            }
        }
        sort(all(v), greater<ll>());
        if(v.size()>20) v.resize(20);
        tops[cur] = v;
        return v;
    };
    solve(0, -1);
    rep(i, Q){
        cout << tops[V[i]-1][K[i]-1] << endl;
    }
}
