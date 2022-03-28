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

    ll N;
    cin >> N;
    vll A(N-1), B(N-1);
    rep(i, N-1) cin >> A[i] >> B[i];

    vector<uset<ll>> e(N);
    rep(i, N-1){
        e[A[i]-1].insert(B[i]-1);
        e[B[i]-1].insert(A[i]-1);
    }
    uset<ll> cur;
    for(auto it=e[0].begin(); it!=e[0].end();){
        ll n = *it;
        cur.insert(n);
        e[0].erase(it++);
        e[n].erase(0);
    }
    ll toggle = 0;
    uset<ll> s = {0};
    while(!cur.empty()){
        uset<ll> tmp;
        for(ll n: cur){
            if(toggle==1) s.insert(n);
            for(auto it=e[n].begin(); it!=e[n].end();){
                ll m = *it;
                e[n].erase(it++);
                e[m].erase(n);
                tmp.insert(m);
            }
        }
        toggle = 1 - toggle;
        cur = tmp;
    }

    if(s.size()>=N/2){
        vll ans(all(s));
        rep(i, N/2-1) cout << ans[i]+1 << " ";
        cout << ans[N/2-1]+1 << endl;
    }
    else{
        vll ans;
        rep(i, N) if(s.find(i)==s.end()) ans.push_back(i);
        rep(i, N/2-1) cout << ans[i]+1 << " ";
        cout << ans[N/2-1]+1 << endl;
    }
}
