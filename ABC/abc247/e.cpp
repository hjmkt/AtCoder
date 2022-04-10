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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, X, Y;
    cin >> N >> X >> Y;
    vll A(N);
    rep(i, N) cin >> A[i];

    vector<bool> b(N, true);
    rep(i, N) b[i] = A[i]<=X && A[i]>=Y;
    ll cont = 0;
    ll ans = 0;
    rep(i, N){
        if(b[i]) ++cont;
        if((!b[i]) || i==N-1){
            if(i==N-1) ++i;
            vll xs(cont+1, 0), ys(cont+1, 0);
            REP(j, i-cont, i){
                if(A[j]==X) xs[j-i+cont+1] = xs[j-i+cont] + 1;
                else xs[j-i+cont+1] = xs[j-i+cont];
                if(A[j]==Y) ys[j-i+cont+1] = ys[j-i+cont] + 1;
                else ys[j-i+cont+1] = ys[j-i+cont];
            }
            REP(j, i-cont, i){
                ll lb = j, ub = i-1;
                while(lb<ub){
                    ll m = (lb+ub) / 2;
                    if(xs[m-i+cont+1]-xs[j-i+cont] > 0 && ys[m-i+cont+1]-ys[j-i+cont] > 0){
                        ub = m;
                    }
                    else{
                        lb = m + 1;
                    }
                }
                if(xs[lb-i+cont+1]-xs[j-i+cont] > 0 && ys[lb-i+cont+1]-ys[j-i+cont] > 0){
                    ans += i - lb;
                }
            }
            cont = 0;
        }
    }
    cout << ans << endl;
}
