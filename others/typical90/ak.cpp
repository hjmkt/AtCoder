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
        else return max(get(left, min((lb+ub)/2, right), level+1, idx*2+1), get(max((lb+ub)/2+1, left), right, level+1, idx*2+2));
    }

    void update(ll x, ll e, ll level=0, ll idx=0){
        ll step = (this->v.size()+1) >> (level+1);
        ll lb = (idx-(1<<level)+1) * step;
        ll ub = lb + step - 1;
        if(lb==x && ub==x){
            this->v[idx] = max(this->v[idx], e);
        }
        else{
            this->v[idx] = max(this->v[idx], e);
            ll mid = (lb+ub) / 2;
            if(x<=mid) update(x, e, level+1, idx*2+1);
            else update(x, e, level+1, idx*2+2);
        }
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll W, N;
    cin >> W >> N;
    vll L(N), R(N), V(N);
    rep(i, N) cin >> L[i] >> R[i] >> V[i];

    SegTree t0(W+1), t1(W+1);
    rep(i, N){
        rep(j, W+1){
            if(j-L[i]>=0){
                ll d = t0.get(max(0ll, j-R[i]), j-L[i]);
                if(d>0) t1.update(j, d+V[i]);
                else if(j-R[i]<=0) t1.update(j, V[i]);
            }
        }
        t0 = t1;
    }
    ll ans = t0.get(W, W);
    if(ans>0) cout << ans << endl;
    else cout << -1 << endl;
}
