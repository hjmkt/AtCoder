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

    ll N;
    cin >> N;
    vll A(N), B(N);
    rep(n, N) cin >> A[n] >> B[n];

    vll d(N, 0);
    ll a = 0, b = 0;
    rep(n, N){
        d[n] = -2*A[n]-B[n];
        a += A[n];
    }
    sort(all(d));
    rep(n, N){
        if(a-b<0){
            cout << n << endl;
            return 0;
        }
        a += d[n];
    }
    cout << N << endl;
}
