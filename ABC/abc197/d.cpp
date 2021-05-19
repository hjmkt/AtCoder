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
    ll x0, y0, xh, yh;
    cin >> x0 >> y0 >> xh >> yh;
    double dx = ((double)xh - x0)/2;
    double dy = ((double)yh - y0)/2;
    double cx = x0 + dx;
    double cy = y0 + dy;
    double dp = -(N/2-1)*M_PI/(N/2);
    double adx = dx*cos(dp) - dy*sin(dp);
    double ady = dx*sin(dp) + dy*cos(dp);
    double ax = cx + adx;
    double ay = cy + ady;
    cout<< ax << " " << ay << endl;
}
