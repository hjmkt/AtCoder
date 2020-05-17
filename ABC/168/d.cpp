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
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, M;
    cin >> N >> M;

    vll A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    vector<unordered_set<ll>> e(N);
    rep(i, M){
        e[A[i]-1].insert(B[i]-1);
        e[B[i]-1].insert(A[i]-1);
    }
    vll c(N, -1);

    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll v = q.front();
        q.pop();
        for(ll nv : e[v]){
            if(c[nv]<0){
                q.push(nv);
                c[nv] = v;
            }
        }
    }

    cout << "Yes" << endl;
    REP(i, 1, N){
        cout << c[i]+1 << endl;
    }
}
