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
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;
    vll x(N), y(N);
    vector<char> d(N);
    rep(i, N) cin >> x[i] >> y[i] >> d[i];

    ll min_cx = 200000000, max_cx = -200000000;
    ll min_cy = 200000000, max_cy = -200000000;
    ll min_rx = 200000000, max_rx = -200000000;
    ll min_lx = 200000000, max_lx = -200000000;
    ll min_uy = 200000000, max_uy = -200000000;
    ll min_dy = 200000000, max_dy = -200000000;

    rep(i, N){
        if(d[i]=='R'){
            min_rx = min(x[i]*2, min_rx);
            max_rx = max(x[i]*2, max_rx);
            min_cy = min(y[i]*2, min_cy);
            max_cy = max(y[i]*2, max_cy);
        }
        else if(d[i]=='L'){
            min_lx = min(x[i]*2, min_lx);
            max_lx = max(x[i]*2, max_lx);
            min_cy = min(y[i]*2, min_cy);
            max_cy = max(y[i]*2, max_cy);
        }
        else if(d[i]=='D'){
            min_dy = min(y[i]*2, min_dy);
            max_dy = max(y[i]*2, max_dy);
            min_cx = min(x[i]*2, min_cx);
            max_cx = max(x[i]*2, max_cx);
        }
        else{
            min_uy = min(y[i]*2, min_uy);
            max_uy = max(y[i]*2, max_uy);
            min_cx = min(x[i]*2, min_cx);
            max_cx = max(x[i]*2, max_cx);
        }
    }

    set<ll> t = {
        0, min_cx-min_rx, (min_lx-min_rx)/2, min_lx-min_cx, max_lx-max_cx, (max_lx-max_rx)/2, max_cx-max_rx,
        min_cy-min_uy, (min_dy-min_uy)/2, min_dy-min_cy, max_dy-max_cy, (max_dy-max_uy)/2, max_cy-max_uy, 400000000,
    };

    ll ans = 1600000000000000000;
    for(ll e : t){
        if(e<0) continue;
        ll w = max({max_cx, max_lx-e, max_rx+e}) - min({min_cx, min_lx-e, min_rx+e});
        ll h = max({max_cy, max_dy-e, max_uy+e}) - min({min_cy, min_dy-e, min_uy+e});
        ans = min(ans, w*h);
    }
    cout << (double)ans/4 << endl;
}
