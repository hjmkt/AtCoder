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

    ll a, b, C;
    cin >> a >> b >> C;

    vector<vector<vector<pair<ll, ll>>>> dp(61, vector<vector<pair<ll, ll>>>(61, vector<pair<ll, ll>>(61, {-1, -1})));
    dp[0][0][0] = {0, 0};
    REP(i, 1, 61){
        ll mask = (1LL<<i) - 1;
        ll c = C & mask;
        // bits of X
        rep(j, min(i+1, a+1)){
            // bits of Y
            rep(k, min(i+1, b+1)){
                ll xy = C & (1LL<<(i-1));
                if(xy==0){
                    if(dp[i-1][j][k].first>=0){
                        dp[i][j][k].first = dp[i-1][j][k].first;
                        dp[i][j][k].second = dp[i-1][j][k].second;
                    }
                    else if(j>0 && k>0 && dp[i-1][j-1][k-1].first>=0){
                        dp[i][j][k].first = dp[i-1][j-1][k-1].first + (1LL<<(i-1));
                        dp[i][j][k].second = dp[i-1][j-1][k-1].second + (1LL<<(i-1));
                    }
                }
                else{
                    if(j>0 && dp[i-1][j-1][k].first>=0){
                        dp[i][j][k].first = dp[i-1][j-1][k].first + (1LL<<(i-1));
                        dp[i][j][k].second = dp[i-1][j-1][k].second;
                    }
                    if(k>0 && dp[i-1][j][k-1].first>=0){
                        dp[i][j][k].first = dp[i-1][j][k-1].first;
                        dp[i][j][k].second = dp[i-1][j][k-1].second + (1LL<<(i-1));
                    }
                }
            }
        }
    }
    if(dp[60][a][b].first<0) cout << -1 << endl;
    else cout << dp[60][a][b].first << " " << dp[60][a][b].second << endl;
}
