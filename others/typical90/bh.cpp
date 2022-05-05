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
    vll A(N);
    rep(i, N) cin >> A[i];

    vector<pair<ll, ll>> lis(N, {0, LLONG_MAX}), lds(N, {0, LLONG_MAX});
    vll dp(N, LLONG_MAX);

    dp[0] = A[0];
    lis[0] = {1, dp[0]};
    REP(i, 1, N){
        lis[i] = lis[i-1];
        ll lb = 0, ub = i-1;
        while(lb<ub){
            ll m = (lb+ub+1) / 2;
            if(dp[m]<A[i]) lb = m;
            else ub = m - 1;
        }
        if(lb==0 && dp[lb]>=A[i]) dp[lb] = A[i];
        else if(dp[lb]<A[i]) {
            if(lb+1+1>lis[i].first) lis[i] = {lb+1+1, A[i]};
            else if(lb+1+1==lis[i].first) lis[i] = {lis[i].first, max(lis[i].second, A[i])};
            dp[lb+1] = min(dp[lb+1], A[i]);
        }
    }

    reverse(all(A));
    dp = vll(N, LLONG_MAX);
    dp[0] = A[0];
    lds[0] = {1, dp[0]};
    REP(i, 1, N){
        lds[i] = lds[i-1];
        ll lb = 0, ub = i-1;
        while(lb<ub){
            ll m = (lb+ub+1) / 2;
            if(dp[m]<A[i]) lb = m;
            else ub = m - 1;
        }
        if(lb==0 && dp[lb]>=A[i]) dp[lb] = A[i];
        else if(dp[lb]<A[i]) {
            if(lb+1+1>lds[i].first) lds[i] = {lb+1+1, A[i]};
            else if(lb+1+1==lds[i].first) lds[i] = {lds[i].first, max(lds[i].second, A[i])};
            dp[lb+1] = min(dp[lb+1], A[i]);
        }
    }

    ll ans = lis.back().first;
    rep(i, N-1){
        if(lis[i].second==lds[N-i-2].second) continue;
        ll m = lis[i].first + lds[N-i-2].first;
        ans = max(ans, m);
    }
    cout << ans << endl;
}
