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

    ll N;
    cin >> N;
    vll W(N), B(N);
    rep(i, N) cin >> W[i];
    rep(i, N) cin >> B[i];

    vvll dp(50+1, vll(50+50*51/2+1, -1));
    dp[0][0] = dp[0][1] = 0;
    function<ll(ll, ll)> f = [&](ll w, ll b){
        if(dp[w][b]>=0) return dp[w][b];
        uset<ll> s;
        if(w>=1) s.insert(f(w-1, b+w));
        if(b>=2){
            REP(n, 1, b/2+1) s.insert(f(w, b-n));
        }
        ll m = 0;
        while(s.find(m)!=s.end()) ++m;
        return dp[w][b] = m;
    };
    ll m = 0;
    rep(i, N) m ^= f(W[i], B[i]);
    if(m==0) cout << "Second" << endl;
    else cout << "First" << endl;
}
