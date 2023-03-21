#include <bits/stdc++.h>
#include <climits>

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

    ll N, K;
    cin >> N >> K;
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vvll dp(1<<N, vll(K+1, LLONG_MAX));
    vvll d2(N, vll(N, 0));
    rep(i, N) rep(j, N) d2[i][j] = (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]);
    vll dists(1<<N, 0);
    rep(i, 1<<N){
        rep(j, N){
            if(((i>>j)&1)==1){
                REP(k, j+1, N){
                    if(((i>>k)&1)==1) dists[i] = max(dists[i], d2[j][k]);
                }
            }
        }
    }
    REP(i, 1, 1<<N) dp[i][1] = dists[i];
    REP(i, 1, 1<<N){
        ll n = 0;
        vll indices;
        rep(j, N){
            if(((i>>j)&1)==1){
                ++n;
                indices.push_back(j);
            }
        }
        REP(k, 1, (1<<n)-1){
            ll b = 0;
            rep(l, n) b |= (((k>>l)&1)<<indices[l]);
            REP(j, 2, K+1){
                dp[i][j] = min(dp[i][j], max(dp[i^b][j-1], dists[b]));
            }
        }
    }
    cout << dp[(1<<N)-1][K] << endl;
}
