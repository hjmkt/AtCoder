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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    vector<string> S(2);
    cin >> S[0] >> S[1];

    UnionFind uf(2*S[0].length());
    unordered_set<ll> s;
    rep(i, 2) rep(j, S[0].length()){
        if(S[i][j]=='#'){
            if(S[1-i][j]=='#'){
                uf.unite(i*S[0].length()+j, (1-i)*S[0].length()+j);
            }
            if(j>0 && S[i][j-1]=='#'){
                uf.unite(i*S[0].length()+j, i*S[0].length()+j-1);
            }
            s.insert(i*S[0].length()+j);
        }
    }
    unordered_set<ll> t;
    for(ll e : s){
        t.insert(uf.root(e));
    }
    if(t.size()==1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
