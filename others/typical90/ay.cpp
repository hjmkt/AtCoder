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

    ll N, K, P;
    cin >> N >> K >> P;
    vll A(N);
    rep(i, N) cin >> A[i];

    if(N==1) {
        if(A[0]<=P) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    vll first(N/2), second(N-N/2);
    rep(i, N/2) first[i] = A[i];
    rep(i, N-N/2) second[i] = A[i+N/2];
    vvll first_sum(K+1), second_sum(K+1);
    rep(i, N/2){
        irep(j, K){
            for(ll n: first_sum[j]) {
                if(n+A[i]<=P) first_sum[j+1].push_back(n+A[i]);
            }
        }
        if(A[i]<=P) first_sum[1].push_back(A[i]);
    }
    rep(i, N-N/2){
        irep(j, K){
            for(ll n: second_sum[j]) {
                if(n+A[i+N/2]<=P) second_sum[j+1].push_back(n+A[i+N/2]);
            }
        }
        if(A[i+N/2]<=P) second_sum[1].push_back(A[i+N/2]);
    }
    rep(i, K+1){
        sort(all(first_sum[i]));
        sort(all(second_sum[i]));
    }
    ll ans = 0;
    rep(i, K+1) {
        ll idx = second_sum[K-i].size() - 1;
        for(ll x: first_sum[i]) {
            while(idx>=0 && x+second_sum[K-i][idx]>P) --idx;
            if(idx<0) break;
            ans += idx + 1;
        }
    }
    ans += first_sum[K].size();
    ans += second_sum[K].size();
    cout << ans << endl;
}
