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

    ll N, S;
    cin >> N >> S;
    vll A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<bool>> dp(N+1, vector<bool>(S+1, false));
    dp[0][0] = true;
    rep(i, N){
        rep(j, S+1){
            if(j-A[i]>=0) dp[i+1][j] = dp[i+1][j] || dp[i][j-A[i]];
            if(j-B[i]>=0) dp[i+1][j] = dp[i+1][j] || dp[i][j-B[i]];
        }
    }
    string ans(N, 'A');
    if(dp[N][S]){
        ll last = S;
        rep(i, N){
            if(last-B[N-i-1]>=0 && dp[N-i-1][last-B[N-i-1]]){
                ans[N-i-1] = 'B';
                last -= B[N-i-1];
            }
            else last -= A[N-i-1];
        }
        cout << ans << endl;
    }
    else cout << "Impossible" << endl;
}
