#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;
template<class T> using mset = multiset<T>;
template<class T, class U> using mmap = multimap<T, U>;
template<class T> using umset = unordered_multiset<T>;
template<class T, class U> using ummap = unordered_multimap<T, U>;

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

    ll N, P;
    cin >> N >> P;

    vvvll dp(N, vvll(N+2, vll(2, 0)));
    dp[0][0][1] = dp[0][1][0] = 1;
    REP(i, 1, N){
        rep(j, N){
            dp[i][j][0] = ((j>=1? dp[i-1][j-1][0] : 0) + 2*(j>=2? dp[i-1][j-2][1] : 0)) % P;
            dp[i][j][1] = (dp[i-1][j][0] + 3*(j>=1? dp[i-1][j-1][1] : 0)+dp[i-1][j][1]) % P;
        }
    }
    REP(i, 1, N-1) cout << dp[N-1][i][1] << " ";
    cout << dp[N-1][N-1][1] << endl;
}
