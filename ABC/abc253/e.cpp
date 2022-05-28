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

ll mod = 998244353;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M, K;
    cin >> N >> M >> K;

    vll v(M, 1);
    REP(i, 1, N){
        vll incl(M, 0), incr(M, 0);
        if(K==0){
            ll s = 0;
            rep(i, M) s = (s+v[i]) % mod;
            rep(i, M) v[i] = s;
        }
        else{
            rep(i, M){
                if(i+K<M) incl[i+K] += v[i];
                if(i-K>=0) incr[i-K] += v[i];
            }
            vll tmp(M, 0);
            ll il = 0, ir = 0;
            rep(i, M){
                il = (il+incl[i]) % mod;
                tmp[i] = (tmp[i]+il) % mod;
            }
            irep(i, M){
                ir = (ir+incr[i]) % mod;
                tmp[i] = (tmp[i]+ir) % mod;
            }
            v = tmp;
        }
    }
    ll ans = 0;
    rep(i, M){
        ans = (ans+v[i]) % mod;
    }
    cout << ans << endl;
}
