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
    vll A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    vvll dp0(N, vll(2, 0)), dp1(N, vll(2, 0));

    dp0[N-1][0] = A[N-1] + B[N-1];
    dp0[N-1][1] = 0;
    irep(i, N-1){
        dp0[i][0] = min(dp0[i+1][0]+A[i]+B[i], dp0[i+1][1]+A[i]);
        dp0[i][1] = min(dp0[i+1][0], dp0[i+1][1]+B[i]);
    }
    ll cost = dp0[0][0];

    dp1[N-1][0] = A[N-1];
    dp1[N-1][1] = B[N-1];
    irep(i, N-1){
        dp1[i][0] = min(dp1[i+1][0]+A[i]+B[i], dp1[i+1][1]+A[i]);
        dp1[i][1] = min(dp1[i+1][0], dp1[i+1][1]+B[i]);
    }
    cost = min(cost, dp1[0][1]);
    cout << cost << endl;
}
