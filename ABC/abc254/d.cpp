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

    set<ll> s;
    REP(i, 1, N+1) s.insert(i*i);

    ll ans = 0;
    REP(i, 1, N+1){
        auto ub = s.upper_bound(i);
        auto it = ub==s.end()? prev(ub) : ub;
        ll d = 1;
        while(it!=s.end()){
            if(i%*it==0){
                d = *it;
                break;
            }
            if(it==s.begin()) break;
            it = prev(it);
        }
        ll r = i / d;
        for(ll n: s){
            if(r*n>N) break;
            ++ans;
        }
    }
    cout << ans << endl;
}
