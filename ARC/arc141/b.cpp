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

    ll N, M;
    cin >> N >> M;
    ll t = M;
    ll l = 0;
    while(t>0){
        ++l;
        t /= 2;
    }
    if(l<N){
        cout << 0 << endl;
        return 0;
    }
    vvll dp(l, vll(N+1, 0));
    dp[0][0] = dp[0][1] = 1;
    ll d = 1;
    REP(i, 1, l){
        d = d*2;
        if(i==l-1){
            dp[i][N] = (dp[i-1][N] + (dp[i-1][N-1]*(M%d%998244353+1))) % 998244353;
            break;
        }
        rep(j, N+1){
            dp[i][j] = (dp[i-1][j] + (j>0? dp[i-1][j-1] : 0)*(d%998244353)) % 998244353;
        }
    }
    ll ans = dp[l-1][N];
    cout << ans << endl;
}
