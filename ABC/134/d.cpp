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
    vll a(N+1);
    rep(i, N){
        cin >> a[i+1];
    }
    vll b(N+1, -1);
    IREP(i, N+1, 1){
        ll count = 0;
        for(ll j=i+i; j<=N; j+=i){
            count += b[j];
        }
        b[i] = (count+a[i]) % 2;
    }
    ll count = 0;
    rep(i, N){
        count += b[i+1];
    }
    cout << count << endl;
    rep(i, N){
        if(b[i+1]>0) cout << (i+1) << endl;
    }
}
