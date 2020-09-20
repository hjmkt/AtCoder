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

    ll N, Q;
    cin >> N >> Q;

    ll h = N-2;
    ll w = N-2;
    ll total = h * w;

    vll hs(N-2, -1), ws(N-2, -1);
    hs[N-3] = ws[N-3] = N-2;

    vll qs(Q), xs(Q);
    rep(i, Q){
        ll q, x;
        cin >> q >> x;
        qs[i] = q;
        xs[i] = x;
        if(q==1){
            w = min(w, x-2);
            if(h>0) ws[h-1] = w;
        }
        else{
            h = min(h, x-2);
            if(w>0) hs[w-1] = h;
        }
    }
    ll idx = N-3;
    while(idx>0){
        if(hs[idx-1]<0) hs[idx-1] = hs[idx];
        if(ws[idx-1]<0) ws[idx-1] = ws[idx];
        --idx;
    }

    rep(i, Q){
        if(qs[i]==1){
            total -= hs[xs[i]-2];
        }
        else{
            total -= ws[xs[i]-2];
        }
    }
    cout << total << endl;
}
