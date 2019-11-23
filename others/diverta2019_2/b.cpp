#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, x) REP(i, 0, x)
#define all(v) v.gein(), v.end()

int main(){
    int N;
    cin >> N;
    vector<pair<ll, ll>> p(N);
    rep(i, N){
        cin >> p[i].first >> p[i].second;
    }
    map<pair<ll, ll>, ll> c;
    ll m = 0;
    rep(i, N){
        REP(j, i+1, N){
            ll dx = p[j].first - p[i].first;
            ll dy = p[j].second - p[i].second;
            if(dx<0){
                dx = -dx;
                dy = -dy;
            }
            else if(dx==0){
                if(dy<0) dy = -dy;
            }
            pair<ll, ll> d = {dx, dy};
            if(c.count(d)>0) ++c[d];
            else c.insert({d, 1});
            if(m<c[d]) m = c[d];
        }
    }
    cout << (N-m) << endl;
}
