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

    ll X;
    cin >> X;

    if(X<10){
        cout << X << endl;
        return 0;
    }

    ll r = 0;
    ll t = X;
    vll ds;
    while(t>0){
        ++r;
        ds.push_back(t%10);
        t /= 10;
    }
    reverse(all(ds));
    REP(i, -9, 10){
        ll n = ds[0];
        bool ok = true;
        bool eq = true;
        ll a = n;
        REP(j, 1, r){
            n += i;
            a = a*10 + n;
            if(n>9 || n<0 || (n<ds[j] && eq)){
                ok = false;
                break;
            }
            if(n>ds[j]) eq = false;
        }
        if(ok){
            cout << a << endl;
            return 0;
        }
    }
    if(ds[0]<9){
        if(r<=ds[0]+2){
            ll a = 0;
            rep(i, r){
                a = a*10 + ds[0]+1-i;
            }
            cout << a << endl;
        }
        else{
            ll a = 0;
            rep(i, r){
                a = a*10 + ds[0]+1;
            }
            cout << a << endl;
        }
    }
    else{
        ll a = 0;
        rep(i, r+1){
            a = a*10 + 1;
        }
        cout << a << endl;
    }
}
