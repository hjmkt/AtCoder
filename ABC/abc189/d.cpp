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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vvll dp(N+1, vll(2, 0));
    dp[N][1] = 1;
    irep(i, N){
        if(S[i]=="AND"){
            dp[i][1] = dp[i+1][0] + dp[i+1][1];
            dp[i][0] = 2*dp[i+1][0];
        }
        else{
            dp[i][0] = dp[i+1][0] + dp[i+1][1];
            dp[i][1] = 2*dp[i+1][1];
        }
    }
    cout << dp[0][0] + dp[0][1] << endl;
}
