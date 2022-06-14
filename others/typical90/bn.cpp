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
    vll L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];
    vector<vector<double>> p(N, vector<double>(N, 0));
    double ans = 0;
    rep(i, N-1){
        REP(j, i+1, N){
            if(R[i]<=L[j]) p[i][j] = 0;
            else if(R[j]<L[i]) p[i][j] = 1;
            else if(L[i]<L[j]){
                double r = min(R[i], R[j]) - max(L[i], L[j]);
                p[i][j] = 0.5 * r * (r+1) / (R[i]-L[i]+1) / (R[j]-L[j]+1) + (double)max(0ll, R[i]-R[j])/(R[i]-L[i]+1);
            }
            else{
                double r = min(R[i], R[j]) - max(L[i], L[j]);
                p[i][j] = 1 - 0.5 * (r+1) * (r+2) / (R[i]-L[i]+1) / (R[j]-L[j]+1) - (double)max(0ll, R[j]-R[i])/(R[j]-L[j]+1);
            }
            ans += p[i][j];
        }
    }
    cout << ans << endl;
}
