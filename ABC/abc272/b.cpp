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

    ll N, M;
    cin >> N >> M;
    vll k(M);
    vvll x(M);
    rep(i, M){
        cin >> k[i];
        x[i] = vll(k[i]);
        rep(j, k[i]) cin >> x[i][j];
    }
    vector<vector<bool>> flags(N, vector<bool>(N, false));
    rep(i, M){
        rep(j, k[i]-1) REP(l, j+1, k[i]){
            flags[x[i][j]-1][x[i][l]-1] = flags[x[i][l]-1][x[i][j]-1] = true;
        }
    }
    rep(i, N-1) REP(j, i+1, N){
        if(!flags[i][j]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
