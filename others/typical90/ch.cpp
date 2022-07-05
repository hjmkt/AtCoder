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

    ll N, Q;
    cin >> N >> Q;
    vll x(Q), y(Q), z(Q), w(Q);
    rep(i, Q) cin >> x[i] >> y[i] >> z[i] >> w[i];

    ll ans = 1;
    rep(i, 60){
        ll m = 0;
        rep(j, 1<<N){
            bool ok = true;
            rep(k, Q){
                ll bx = (j>>(x[k]-1)) & 1;
                ll by = (j>>(y[k]-1)) & 1;
                ll bz = (j>>(z[k]-1)) & 1;
                ll bw = (w[k]>>i) & 1;
                if((bx|by|bz)!=bw){
                    ok = false;
                    break;
                }
            }
            if(ok) ++m;
        }
        ans = ans * m % 1000000007;
    }
    cout << ans << endl;
}
