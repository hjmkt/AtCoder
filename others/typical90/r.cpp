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

    ll T, L, X, Y, Q;
    cin >> T >> L >> X >> Y >> Q;
    vll E(Q);
    rep(i, Q) cin >> E[i];

    rep(i, Q){
        double cx = 0;
        double cy = cos(3.0*M_PI/2.0-2.0*M_PI*E[i]/T)*L/2.0;
        double cz = sin(3.0*M_PI/2.0-2.0*M_PI*E[i]/T)*L/2.0 + L/2.0;
        double dh = sqrt((cx-X)*(cx-X)+(cy-Y)*(cy-Y));
        double dv = cz;
        double angle = atan2(dv, dh) / M_PI * 180;
        cout << angle << endl;
    }
}
