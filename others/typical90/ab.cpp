#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

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
    vll lx(N), ly(N), rx(N), ry(N);
    rep(i, N) cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];

    vvll t(1001, vll(1001, 0));
    rep(i, N){
        REP(y, ly[i], ry[i]){
            ++t[y][lx[i]];
            --t[y][rx[i]];
        }
    }

    vll ans(N+1, 0);
    rep(y, 1001){
        ll n = 0;
        rep(x, 1001){
            n += t[y][x];
            ++ans[n];
        }
    }
    rep(i, N) cout << ans[i+1] << endl;
}
