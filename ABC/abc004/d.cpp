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
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll r, g, b;
    cin >> r >> g >> b;

    ll best = 1<<30;
    REP(gl, -350, 350+1){
        ll gleft = gl;
        ll gright = gleft+g-1;
        ll total = gleft*gright<0? (abs(gleft)*(abs(gleft)+1)/2+abs(gright)*(abs(gright)+1)/2) : (g*min(abs(gleft), abs(gright))+abs(gleft-gright)*(abs(gleft-gright)+1)/2);

        if(gleft>-100){
            ll rright = min(r/2, 100+gleft-1);
            total += rright*(rright+1)/2 + (r-rright-1)*(r-rright)/2;
        }
        else total += r*(abs(gleft+100)+1) + (r-1)*r/2;

        if(gright<100){
            ll bleft = min(b/2, 100-gright-1);
            total += bleft*(bleft+1)/2 + (b-bleft-1)*(b-bleft)/2;
        }
        else total += b*(gright-100+1) + (b-1)*b/2;
        best = min(best, total);
    }
    cout << best << endl;
}
