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

    ll Q;
    cin >> Q;
    map<ll, ll> m;
    rep(i, Q){
        ll n;
        cin >> n;
        if(n==1){
            ll x;
            cin >> x;
            if(m.find(x)==m.end()){
                m[x] = 1;
            }
            else{
                ++m[x];
            }
        }
        else if(n==2){
            ll x, c;
            cin >> x >> c;
            m[x] = max(0ll, m[x]-c);
            if(m[x]==0) m.erase(x);
        }
        else{
            ll mn = m.begin()->first;
            ll mx = m.rbegin()->first;
            cout << mx-mn << endl;
        }
    }
}
