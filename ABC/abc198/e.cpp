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
    vll C(N);
    rep(i, N) cin >> C[i];
    vll A(N-1), B(N-1);
    rep(i, N-1) cin >> A[i] >> B[i];

    vector<set<ll>> e(N);
    rep(i, N-1){
        e[A[i]-1].insert(B[i]-1);
        e[B[i]-1].insert(A[i]-1);
    }

    vll a(N, -1);
    vll c(100001, 0);

    function<void(ll, ll)> solve = [&](ll cur, ll prev){
        if(c[C[cur]]==0){
            a[cur] = 1;
        }
        bool update = c[C[cur]]==0;
        c[C[cur]] = 1;
        auto nexts = e[cur];
        for(ll next : nexts){
            if(next==prev) continue;
            solve(next, cur);
        }
        if(update) c[C[cur]] = 0;
    };

    solve(0, -1);
    rep(i, N){
        if(a[i]==1) cout << i+1 << endl;
    }
}
