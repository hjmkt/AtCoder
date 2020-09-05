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

int main(){
    ll n, m;
    cin >> n >> m;
    vvll st(n, vll(n, 0));
    vll p(n, 0);

    rep(i, m){
        ll s, t;
        cin >> s >> t;
        st[s-1][t-1] = 1;
        ++p[s-1];
    }

    vector<double> e(n, 0);
    IREP(i, n-1, 0){
        double s = 0;
        ll count = 0;
        REP(j, i+1, n){
            if(st[i][j]==1){
                ++count;
                s += e[j]+1;
            }
        }
        e[i] = s/count;
    }
    vector<double> rp(n, 0);
    rp[0] = 1;
    REP(i, 1, n){
        rep(j, i){
            if(st[j][i]==1){
                rp[i] += rp[j]/p[j];
            }
        }
    }
    double res = e[0];
    rep(i, n){
        if(p[i]>=2){
            double t = 0;
            REP(j, i+1, n){
                if(st[i][j]==1){
                    t = max(t, e[j]+1);
                }
            }
            double ne = (e[i]*p[i]-t) / (p[i]-1);
            res = min(res, e[0]-(e[i]-ne)*rp[i]);
        }
    }
    cout << setprecision(20) << res << endl;
}
