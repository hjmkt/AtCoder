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
    vll x(N), y(N), P(N);
    rep(i, N) cin >> x[i] >> y[i] >> P[i];

    ll lb = 0, ub = 4000000000;
    while(lb<ub){
        ll m = (lb+ub) / 2;
        bool ok = false;
        rep(i, N){
            vector<bool> checked(N, false);
            queue<ll> q;
            q.push(i);
            checked[i] = true;
            while(!q.empty()){
                ll n = q.front();
                q.pop();
                rep(j, N){
                    if(checked[j]) continue;
                    if(abs(x[n]-x[j])+abs(y[n]-y[j])<=P[n]*m){
                        checked[j] = true;
                        q.push(j);
                    }
                }
            }
            ll count = 0;
            rep(i, N){
                if(checked[i]) ++count;
            }
            if(count==N){
                ok = true;
                break;
            }
        }
        if(ok){
            ub = m;
        }
        else{
            lb = m + 1;
        }
    }
    cout << lb << endl;
}
