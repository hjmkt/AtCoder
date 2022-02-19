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

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(ll x=x1-2; x<=x1+2; ++x){
        for(ll y=y1-2; y<=y1+2; ++y){
            ll dx1 = abs(x-x1);
            ll dx2 = abs(x-x2);
            ll dy1 = abs(y-y1);
            ll dy2 = abs(y-y2);
            if(dx1*dy1==2 && dx2*dy2==2){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
