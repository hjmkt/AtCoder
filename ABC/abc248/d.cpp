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

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];
    ll Q;
    cin >> Q;

    vvll v(N);
    rep(i, N) v[A[i]-1].push_back(i);

    rep(i, Q){
        ll L, R, X;
        cin >> L >> R >> X;
        if(v[X-1].empty()){
            cout << 0 << endl;
            continue;
        }
        if(v[X-1].back()<L-1 || v[X-1][0]>R-1){
            cout << 0 << endl;
            continue;
        }
        ll lb = 0, ub = v[X-1].size()-1;
        while(lb<ub){
            ll mid = (lb+ub) / 2;
            if(v[X-1][mid]<L-1){
                lb = mid + 1;
            }
            else{
                ub = mid;
            }
        }
        ll l = lb;
        lb = 0, ub = v[X-1].size()-1;
        while(lb<ub){
            ll mid = (lb+ub+1) / 2;
            if(v[X-1][mid]>R-1){
                ub = mid - 1;
            }
            else{
                lb = mid;
            }
        }
        ll r = lb;
        cout << r-l+1 << endl;
    }
}
