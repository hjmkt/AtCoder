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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;
    vll a(N-1), b(N-1);
    rep(n, N-1) cin >> a[n] >> b[n];
    ll Q;
    cin >> Q;
    vll t(Q), e(Q), x(Q);
    rep(q, Q) cin >> t[q] >> e[q] >> x[q];

    unordered_map<ll, unordered_set<ll>> m;
    rep(n, N-1){
        m[a[n]-1].insert(b[n]-1);
        m[b[n]-1].insert(a[n]-1);
    }
    vll parent(N, -1), c1(N, 0);
    vector<unordered_set<ll>> children(N);
    unordered_set<ll> s = {0};
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll n = q.front();
        q.pop();
        for(ll v : m[n]){
            if(s.count(v)==0){
                parent[v] = n;
                children[n].insert(v);
                s.insert(v);
                q.push(v);
            }
        }
    }

    rep(q, Q){
        if(t[q]==1){
            if(parent[a[e[q]-1]-1]==b[e[q]-1]-1){
                c1[a[e[q]-1]-1] += x[q];
            }
            else{
                c1[0] += x[q];
                c1[b[e[q]-1]-1] -= x[q];
            }
        }
        else{
            if(parent[b[e[q]-1]-1]==a[e[q]-1]-1){
                c1[b[e[q]-1]-1] += x[q];
            }
            else{
                c1[0] += x[q];
                c1[a[e[q]-1]-1] -= x[q];
            }
        }
    }

    vll res(N, 0);
    function<void(ll, ll)> solve = [&](ll n, ll r){
        r += c1[n];
        res[n] = r;
        for(ll v : children[n]){
            solve(v, r);
        }
    };
    solve(0, 0);

    rep(n, N){
        cout << res[n] << endl;
    }
}
