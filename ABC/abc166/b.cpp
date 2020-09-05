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
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, K;
    cin >> N >> K;
    vll d(K);
    vvll A(K);
    rep(i, K){
        cin >> d[i];
        A[i] = vll(d[i]);
        rep(j, d[i]) cin >> A[i][j];
    }

    vll c(N, 0);
    rep(i, K) rep(j, d[i]){
        c[A[i][j]-1] = 1;
    }
    ll count = 0;
    rep(i, N){
        if(c[i]==0) ++count;
    }
    cout << count << endl;
}
