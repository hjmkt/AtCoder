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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M, Q;
    cin >> N >> M >> Q;

    vll a(Q), b(Q), c(Q), d(Q);
    rep(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    function<ll(vll&, ll, ll)> solve = [&](vll &A, ll idx, ll cur){
        if(cur>M) return 0ll;
        if(idx>=N){
            ll total = 0;
            rep(i, Q){
                if(A[b[i]-1]-A[a[i]-1]==c[i]) total += d[i];
            }
            return total;
        }
        else{
            A[idx] = cur;
            ll t1 = solve(A, idx+1, cur);
            A[idx] = cur+1;
            ll t2 = solve(A, idx, cur+1);
            return max(t1, t2);
        }
    };

    vll t(N, 0);
    cout << solve(t, 0, 1) << endl;
}
