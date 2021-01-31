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

class FenwickTree{
    public:
        ll size;
        vll v;

        FenwickTree(ll n){
            this->size = n;
            ll m = 1;
            while(n>m) m *= 2;
            this->v = vll(m, 0);
        }

        ll _get(ll x){
            ll lsb = x & -x;
            ll r = x - lsb;
            if(r>0) return this->v[x-1] + _get(r);
            return this->v[x-1];
        }

        ll get(ll left, ll right){
            if(left<=0) return _get(right+1);
            return _get(right+1) - _get(left);
        }

        void update(ll x, ll e){
            this->v[x] += e;
            if(x==this->v.size()-1) return;
            ll lsb = (x+1) & -(x+1);
            update(x+lsb, e);
        }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;
    vll a(N);
    rep(i, N) cin >> a[i];

    FenwickTree t(N);

    ll ans = 0;
    rep(i, N){
        ans += t.get(a[i], N-1);
        t.update(a[i], 1);
    }
    rep(i, N){
        cout << ans << endl;
        ans += ((N-1-a[i])-a[i]);
    }
}
