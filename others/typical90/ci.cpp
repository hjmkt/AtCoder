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

template<typename T=ll>
void warshall(vector<vector<T>> &v, function<bool(const T&, const T&)> comp=less<T>()){
    ll n = v.size();
    rep(i, n) rep(j, n) rep(k, n){
        v[j][k] = comp(v[j][k], v[j][i]+v[i][k])? v[j][k] : (v[j][i]+v[i][k]);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, P, K;
    cin >> N >> P >> K;
    vvll A(N, vll(N, 0));
    rep(i, N) rep(j, N) cin >> A[i][j];

    ll lb = 0, ub = P;
    while(lb<ub){
        ll m = (lb+ub) / 2;
        vvll a = A;
        rep(i, N) rep(j, N) {
            if(a[i][j]==-1) a[i][j] = m;
        }
        warshall(a);
        ll count = 0;
        rep(i, N-1) REP(j, i+1, N){
            if(a[i][j]<=P) ++count;
        }
        if(count<=K){
            ub = m - 1;
        }
        else{
            lb = m + 1;
        }
    }
}
