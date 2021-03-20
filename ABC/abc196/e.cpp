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
    vll a(N), t(N);
    rep(i, N) cin >> a[i] >> t[i];
    ll Q;
    cin >> Q;
    vll x(Q);
    rep(i, Q) cin >> x[i];

    ll s = LLONG_MIN;
    ll e = LLONG_MAX;
    ll d = 0;
    bool flat = false;
    ll f = 0;
    rep(i, N){
        if(t[i]==1){
            d += a[i];
            f += a[i];
        }
        else if(t[i]==2){
            s = max(s, a[i] - d);
            if(s>=e){
                if(!flat) f = a[i];
                flat = true;
            }
            if(flat){
                f = max(f, a[i]);
            }
        }
        else{
            e = min(e, a[i] - d);
            if(s>=e){
                if(!flat) f = a[i];
                flat = true;
            }
            if(flat){
                f = min(f, a[i]);
            }
        }
    }
    rep(i, Q){
        if(flat){
            cout << f << endl;
            continue;
        }
        if(x[i]<s){
            cout << d+s << endl;
        }
        else if(x[i]<e){
            cout << d+x[i] << endl;
        }
        else{
            cout << d+e << endl;
        }
    }
}
