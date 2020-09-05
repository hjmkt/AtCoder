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
    vll a(N+1), b(N);
    rep(i, N+1){
        cin >> a[i];
    }
    rep(i, N){
        cin >> b[i];
    }
    ll count = 0;
    rep(i, N){
        ll first = min(b[i], a[i]);
        count += first;
        b[i] -= first;
        ll second = min(b[i], a[i+1]);
        count += second;
        a[i+1] -= second;
    }
    cout << count << endl;
}
