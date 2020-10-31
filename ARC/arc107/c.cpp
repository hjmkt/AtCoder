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

class UnionFind{
    public:
        ll size;
        vll v;

        UnionFind(ll n){
            this->v = vll(n);
            rep(i, n) this->v[i] = i;
        }

        ll root(ll n){
            if(n!=v[n]) return v[n] = root(v[n]);
            return n;
        }

        void unite(ll l, ll r){
            ll lroot = root(l);
            ll rroot = root(r);
            if(lroot!=rroot) this->v[rroot] = lroot;
        }
};

ll fac(ll n, ll mod=998244353){
    static const ll N_MAX = 200001;
    static vll fac(N_MAX+1, -1);

    if(fac[0]<0){
        fac[0] = 1;
        rep(i, N_MAX){
            fac[i+1] = fac[i] * (i+1) % mod;
        }
    }

    return fac[n] % mod;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, K;
    cin >> N >> K;
    vvll a(N, vll(N, 0));
    rep(i, N) rep(j, N){
        cin >> a[i][j];
    }

    UnionFind ufx(N), ufy(N);
    rep(i, N) REP(j, i+1, N){
        bool okx = true, oky = true;
        rep(k, N){
            okx &= a[k][i]+a[k][j] <= K;
            oky &= a[i][k]+a[j][k] <= K;
        }
        if(okx) ufx.unite(i, j);
        if(oky) ufy.unite(i, j);
    }

    unordered_map<ll, unordered_set<ll>> mx, my;
    rep(i, N){
        ll rx = ufx.root(i);
        ll ry = ufy.root(i);
        mx[rx].insert(i);
        my[ry].insert(i);
    }

    ll cx = 1, cy = 1;
    for(auto p : mx){
        cx = cx*fac(p.second.size()) % 998244353;
    }
    for(auto p : my){
        cy = cy*fac(p.second.size()) % 998244353;
    }
    ll ans = cx*cy % 998244353;
    cout << ans << endl;
}
