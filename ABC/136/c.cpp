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
    vll h(N);
    rep(i, N){
        cin >> h[i];
    }
    bool p = true;
    --h[0];
    REP(i, 1, N){
        if(h[i]>h[i-1]){
            --h[i];
        }
        else if(h[i]<h[i-1]){
            p = false;
            break;
        }
    }
    if(p) cout << "Yes" << endl;
    else cout << "No" << endl;
}
