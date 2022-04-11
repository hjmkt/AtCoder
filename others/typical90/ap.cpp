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

ll MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll K;
    cin >> K;
    if(K%9!=0){
        cout << 0 << endl;
        return 0;
    }

    vvll dp(K, vll(9, 0));
    rep(i, min(K, 9ll)) dp[i][i] = 1;
    REP(i, 1, K){
        rep(j, 9){
            if(i-j-1>=0){
                rep(k, 9) dp[i][j] = (dp[i][j] + dp[i-j-1][k]) % MOD;
            }
        }
    }
    ll ans = 0;
    rep(i, 9) ans = (ans+dp[K-1][i]) % MOD;
    cout << ans << endl;
}
