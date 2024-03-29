#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

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

    ll H, W;
    cin >> H >> W;
    vvll A(H, vll(W, 0));
    rep(h, H) rep (w, W) cin >> A[h][w];

    REP(i1, 1, H+1) REP(i2, i1+1, H+1) REP(j1, 1, W+1) REP(j2, j1+1, W+1) {
        if(A[i1-1][j1-1]+A[i2-1][j2-1]>A[i2-1][j1-1]+A[i1-1][j2-1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
