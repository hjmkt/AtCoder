#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;
template<class T> using mset = multiset<T>;
template<class T, class U> using mmap = multimap<T, U>;
template<class T> using umset = unordered_multiset<T>;
template<class T, class U> using ummap = unordered_multimap<T, U>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

class SegTree{
public:
    ll size;
    vll v;
    vll lv;

    SegTree(ll n){
        this->size = n;
        ll m = 1;
        while(n>m) m *= 2;
        this->v = vll(2*m-1, 0);
        this->lv = vll(2*m-1, 0);
    }

    ll get(ll left, ll right, ll level=0, ll idx=0){
        if(left>right) return 0;
        ll step = (this->v.size()+1) >> (level+1);
        ll lb = (idx-(1<<level)+1) * step;
        ll ub = lb + step - 1;
        if(lb==left && ub==right){
            return v[idx];
        }
        else return (get(left, min((lb+ub)/2, right), level+1, idx*2+1) + get(max((lb+ub)/2+1, left), right, level+1, idx*2+2)) % 998244353;
    }

    void update(ll x, ll e, ll level=0, ll idx=0){
        ll step = (this->v.size()+1) >> (level+1);
        ll lb = (idx-(1<<level)+1) * step;
        ll ub = lb + step - 1;
        if(lb==x && ub==x){
            this->v[idx] = (this->v[idx] + e) % 998244353;
        }
        else{
            this->v[idx] = (this->v[idx] + e) % 998244353;
            ll mid = (lb+ub) / 2;
            if(x<=mid) update(x, e, level+1, idx*2+1);
            else update(x, e, level+1, idx*2+2);
        }
    }
};

ll pow_mod(ll n, ll m, ll mod=998244353){
    ll a = 1;
    while(m>0){
        if(m&1) a = a*n % mod;
        n = n*n % mod;
        m >>= 1;
    }
    return a;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    rep(i, N) cin >> A[i];

    ll div2 = pow_mod(2, 998244353-2);

    SegTree st0(N), st1(N), st2(N);

    rep(i, N){
        st0.update(i, A[i]);
        st1.update(i, (1-2*i)*A[i]%998244353);
        st2.update(i, (i*(i-1)/2 % 998244353)*A[i] % 998244353);
    }

    rep(i, Q){
        ll t;
        cin >> t;
        if(t==1){
            ll x, v;
            cin >> x >> v;
            --x;
            ll r = st0.get(x, x);
            st0.update(x, v-r);
            r = st1.get(x, x);
            st1.update(x, (1-2*x)*v%998244353-r);
            r = st2.get(x, x);
            st2.update(x, (x*(x-1)/2 % 998244353)*v % 998244353-r);
        }
        else{
            ll x;
            cin >> x;
            ll ans = (st0.get(0, x-1) * x%998244353*x%998244353 + st1.get(0, x-1) * x%998244353 + st2.get(0, x-1)*2) % 998244353;
            ans = ((ans * div2) % 998244353 + 998244353) % 998244353;
            cout << ans << endl;
        }
    }
}
