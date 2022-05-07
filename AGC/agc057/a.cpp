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

    ll T;
    cin >> T;
    rep(_, T){
        ll L, R;
        cin >> L >> R;
        ll dl = 0, dr = 0;
        ll tl = L, tr = R;
        while(tl>0){
            ++dl;
            tl /= 10;
        }
        while(tr>0){
            ++dr;
            tr /= 10;
        }
        if(dl==dr){
            cout << R-L+1 << endl;
        }
        else{
            ll s = R/10;
            L = max(s+1, L);
            ll t = 1;
            rep(i, dr-1) t *= 10;
            if(R/t>=2) L = max(L, t);
            t = R % t;
            L = max(t+1, L);
            cout << R-L+1 << endl;
        }
    }
}
