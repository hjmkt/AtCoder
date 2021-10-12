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
    string S;
    cin >> S;

    vvll dp(N+1, vll(7, 0));
    unordered_map<char, ll> m = {{'a', 0}, {'t', 1}, {'c', 2}, {'o', 3}, {'d', 4}, {'e', 5}, {'r', 6}};
    rep(i, N){
        rep(j, 7) dp[i+1][j] = dp[i][j];
        if(S[i]=='a') dp[i+1][0] += 1;
        else if(m.find(S[i])!=m.end()) dp[i+1][m[S[i]]] += dp[i][m[S[i]]-1];
        rep(j, 7) dp[i+1][j] %= 1000000007;
    }
    cout << dp[N][6] << endl;
}
