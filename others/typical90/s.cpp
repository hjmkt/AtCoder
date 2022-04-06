#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

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
    vll A(2*N);
    rep(i, 2*N) cin >> A[i];

    vvll dp(2*N-1, vll(N, LLONG_MAX));
    rep(i, 2*N-1) dp[i][0] = abs(A[i]-A[i+1]);
    REP(i, 1, N) {
        rep(j, 2*N-1){
            if(j+2*i+1>=2*N) continue;
            dp[j][i] = min(dp[j][i], abs(A[j]-A[j+i*2+1])+dp[j+1][i-1]);
            rep(k, i) dp[j][i] = min(dp[j][i], dp[j][k]+dp[j+2*k+2][i-k-1]);
        }
    }
    ll ans = dp[0].back();
    cout << ans << endl;
}
