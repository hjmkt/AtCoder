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
    vector<char> S(N);
    rep(i, N) cin >> A[i] >> S[i];
    vll L, R;
    rep(i, N){
        if(S[i] == 'L'){
            L.push_back(A[i]);
        }else{
            R.push_back(A[i]);
        }
    }
    ll ans = 0;
    if(L.size()>1){
        ll l = L[0];
        REP(i, 1, L.size()){
            ans += abs(l - L[i]);
            l = L[i];
        }
    }
    if(R.size()>1){
        ll r = R[0];
        REP(i, 1, R.size()){
            ans += abs(r - R[i]);
            r = R[i];
        }
    }
    cout << ans << endl;
}
