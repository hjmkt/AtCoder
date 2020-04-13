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

int main(){
    cout << setprecision(20);

    ll N;
    cin >> N;

    vll a(N, 0);
    rep(i, N) cin >> a[i];

    vvll dp(N, vll(3, 0));
    irep(i, N){
        dp[i][0] = a[i] + ((i+2)<N? dp[i+2][0] : 0);
        if(i+1<N) dp[i][1] = a[i] + ((i+3)<N? max(dp[i+3][0], dp[i+2][1]) : (i+2)<N? dp[i+2][1] : 0);
        if(i+2<N) dp[i][2] = a[i] + ((i+4)<N? max(dp[i+4][0], max(dp[i+3][1], dp[i+2][2])) : (i+3)<N? max(dp[i+3][1], dp[i+2][2]) : (i+2)<N? dp[i+2][2] : 0);
    }
    ll total = N%2==0? max(dp[0][1], dp[1][0]) : max(dp[0][2], max(dp[1][1], dp[2][0]));
    cout << total << endl;
}
