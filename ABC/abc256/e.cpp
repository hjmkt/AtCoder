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
    vll X(N), C(N);
    rep(i, N){
        cin >> X[i];
        --X[i];
    }
    rep(i, N) cin >> C[i];

    ll ans = 0;
    vector<bool> checked(N, false);
    rep(i, N){
        if(checked[i]) continue;
        vll v;
        ll n = -1;
        ll cur = i;
        uset<ll> s;
        while(n!=cur){
            if(s.find(cur)!=s.end()){
                n = cur;
                break;
            }
            if(checked[cur]) break;
            v.push_back(cur);
            s.insert(cur);
            cur = X[cur];
        }
        for(ll e: s) checked[e] = true;
        if(n>=0){
            ll mn = LLONG_MAX;
            bool loop = false;
            for(auto e: v){
                if(e==n) loop = true;
                if(loop) mn = min(mn, C[e]);
            }
            ans += mn;
        }
    }
    cout << ans << endl;
}
