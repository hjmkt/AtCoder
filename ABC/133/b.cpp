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
    ll N, D;
    cin >> N >> D;
    vvll x(N, vll(D, 0));
    rep(i, N){
        rep(j, D){
            cin >> x[i][j];
        }
    }
    ll count = 0;
    rep(i, N){
        REP(j, i+1, N){
            ll sum = 0;
            rep(k, D){
                sum += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
            }
            ll sq = sqrt(sum);
            if(sq*sq==sum) ++count;
        }
    }
    cout << count << endl;
}
