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

    ll N, A, B;
    cin >> N >> A >> B;
    vll D(N);
    rep(i, N) cin >> D[i];
    rep(i, N) D[i] %= (A+B);
    set<ll> s;
    rep(i, N) s.insert(D[i]);
    D = vll(all(s));
    ll d = LLONG_MAX;
    N = D.size();
    rep(i, N){
        ll t = D[(i-1+N)%N]-D[i];
        t = (t%(A+B)+A+B)%(A+B);
        d = min(d, t);
    }
    if(d<A) cout << "Yes" << endl;
    else cout << "No" << endl;
}
