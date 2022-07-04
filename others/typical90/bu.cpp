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

    ll N;
    cin >> N;
    vector<char> c(N);
    rep(i, N) cin >> c[i];
    vll a(N-1), b(N-1);
    rep(i, N-1) cin >> a[i] >> b[i];

    vvll dp(N, vll(4, -1));
    vector<set<ll>> g(N);
    rep(i, N-1){
        g[a[i]-1].insert(b[i]-1);
        g[b[i]-1].insert(a[i]-1);
    }

    ll M = 1000000007;

    function<ll(ll, ll, ll)> solve = [&](ll cur, ll prev, ll state){
        if(dp[cur][state]>=0) return dp[cur][state];
        ll idx = 1<<(ll)(c[cur]-'a');
        if((idx&state)==0) return dp[cur][state]=0ll;
        vll nexts;
        for(auto n: g[cur]){
            if(n==prev) continue;
            nexts.push_back(n);
        }
        if(nexts.empty()){
            return dp[cur][state] = state==idx? 1ll : 0ll;
        }
        if(state<0b11){
            ll count = 1;
            for(ll next: nexts){
                count *= solve(next, cur, idx) + solve(next, cur, 0b11);
                count %= M;
            }
            return dp[cur][state] = count;
        }
        else{
            ll count = 1;
            for(ll next: nexts){
                count *= solve(next, cur, 0b01) + solve(next, cur, 0b10) + 2*solve(next, cur, 0b11);
                count %= M;
            }
            ll r = 1;
            for(ll next: nexts){
                r *= solve(next, cur, idx) + solve(next, cur, 0b11);
                r %= M;
            }
            count = ((count-r)%M+M) % M;
            return dp[cur][state] = count;
        }
    };
    ll ans = solve(0, -1, 0b11);
    cout << ans << endl;
}
