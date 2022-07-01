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
        else return get(left, min((lb+ub)/2, right), level+1, idx*2+1) + get(max((lb+ub)/2+1, left), right, level+1, idx*2+2);
    }

    void update(ll x, ll e, ll level=0, ll idx=0){
        ll step = (this->v.size()+1) >> (level+1);
        ll lb = (idx-(1<<level)+1) * step;
        ll ub = lb + step - 1;
        if(lb==x && ub==x){
            this->v[idx] += e;
        }
        else{
            this->v[idx] += e;
            ll mid = (lb+ub) / 2;
            if(x<=mid) update(x, e, level+1, idx*2+1);
            else update(x, e, level+1, idx*2+2);
        }
    }
};

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, Q;
    cin >> N >> Q;
    vll T(Q), X(Q), Y(Q), V(Q);
    rep(i, Q){
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
        --X[i];
        --Y[i];
        if(T[i]==0 && X[i]%2==1) V[i] = -V[i];
    }

    UnionFind uf(N);
    SegTree st(N);

    rep(i, Q){
        if(T[i]==0){
            if(uf.root(X[i])!=uf.root(Y[i])){
                uf.unite(X[i], Y[i]);
                st.update(X[i], V[i]);
            }
        }
        else {
            if(uf.root(X[i])!=uf.root(Y[i])) cout << "Ambiguous" << endl;
            else if(X[i]<Y[i]) {
                cout << (V[i]*(X[i]%2==0? -1 : 1) + st.get(X[i], Y[i]-1)) * (Y[i]%2==0? -1 : 1) << endl;
            } else if (X[i]>Y[i]){
                cout << (V[i]*(X[i]%2==0? -1 : 1) - st.get(Y[i], X[i]-1)) * (Y[i]%2==0? -1 : 1) << endl;
            } else cout << V[i] << endl;
        }
    }
}
