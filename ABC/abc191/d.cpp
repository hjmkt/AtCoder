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

    double X, Y, R;
    cin >> X >> Y >> R;

    ll ir = (R>=0? (R+0.00001) : (R-0.00001))*10000;
    ll ix = (X>=0? (X+0.00001) : (X-0.00001))*10000;
    ll iy = (Y>=0? (Y+0.00001) : (Y-0.00001))*10000;

    ll sx = ix - ir;
    ll ex = ix + ir;
    ll count = 0;
    for(ll x = (sx<=0? sx/10000*10000 : ((sx-1)/10000+1)*10000); x<=(ex>=0? ex/10000*10000 : ((ex+1)/10000-1)*10000); x+=10000){
        if(ir>=abs(ix-x)){
            ll t = ir*ir - (ix-x)*(ix-x);
            // (iy-y)^2 <= t
            ll left = 0, right = ir;
            while(left<right){
                ll mid = (left+right+1) / 2;
                if(mid*mid<=t){
                    left = mid;
                }
                else{
                    right = mid - 1;
                }
            }
            ll s = (iy-left);
            ll e = (iy+left);
            if(s<=0) s /= 10000;
            else s = (s-1)/10000 + 1;
            if(e>=0) e /= 10000;
            else e = (e+1)/10000 - 1;
            count += e - s + 1;
        }
    }
    cout << count << endl;
}
