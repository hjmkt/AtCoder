#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

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

    ll N, M;
    cin >> N >> M;
    vll A(N), B(N), C(M), D(M);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, M) cin >> C[i];
    rep(i, M) cin >> D[i];

    multiset<tuple<ll, ll, ll>> s;
    rep(i, N) s.insert({A[i], B[i], 0});
    rep(i, M) s.insert({C[i], D[i], 1});
    multiset<ll> t;

    for(auto it=s.rbegin(); it!=s.rend(); ++it){
        auto [h, w, b] = *it;
        if(b==1) t.insert(w);
        else{
            auto itw = t.lower_bound(w);
            if(itw==t.end()){
                cout << "No" << endl;
                return 0;
            }
            else{
                t.erase(itw);
            }
        }
    }
    cout << "Yes" << endl;
}
