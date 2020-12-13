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

    ll N, M, T;
    cin >> N >> M >> T;
    vll A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    ll t = 0;
    ll n = N;
    rep(i, M){
        if(n<=A[i]-t){
            cout << "No" << endl;
            return 0;
        }
        n -= A[i] - t;
        n = min(N, n+B[i]-A[i]);
        t = B[i];
    }
    if(n<=T-t) cout << "No" << endl;
    else cout << "Yes" << endl;
}
