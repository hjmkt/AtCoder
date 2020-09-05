#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()

int main(){
    ll N;
    cin >> N;
    vll a(N);
    rep(i, N){
        cin >> a[i];
    }
    vll x(N);
    ll sx = 0;
    rep(i, N){
        sx += a[i];
    }
    ll st = 0;
    for(ll i=0; i<N-1; i+=2){
        st += a[i];
    }
    x[N-1] = sx - st*2;
    irep(i, N-1){
        x[i] = 2*a[i] - x[i+1];
    }
    rep(i, N-1){
        cout << x[i] << " ";
    }
    cout << x[N-1] << endl;
}
