#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vvvvll = vector<vvvll>;
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

    ll N;
    cin >> N;
    vll a(N);
    rep(i, N) cin >> a[i];

    vvvvll dp(N, vvvll(N+1, vvll(N, vll(N, 0))));
    rep(i, N) ++dp[0][0][i][0];
    rep(i, N) ++dp[0][1][i][a[0]%(i+1)];

    REP(i, 1, N){
        rep(j, N+1){
            rep(k, N){
                rep(l, N){
                    dp[i][j][k][l] = (dp[i-1][j][k][l] + (j>0? dp[i-1][j-1][k][((l-a[i])%(k+1)+k+1)%(k+1)] : 0)) % 998244353;
                }
            }
        }
    }
    ll ans = 0;
    REP(i, 1, N+1){
        ans = (ans + dp[N-1][i][i-1][0]) % 998244353;
    }
    cout << ans << endl;
}
