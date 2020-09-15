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

    ll N, K;
    cin >> N >> K;

    if(K>(N-1)*(N-2)/2) cout << -1 << endl;
    else{
        vvll edges = {};
        REP(i, 2, N+1) edges.push_back({1, i});
        ll r = (N-1)*(N-2)/2 - K;
        REP(i, 2, N){
            if(r==0) break;
            REP(j, i+1, N+1){
                if(r==0) break;
                edges.push_back({i, j});
                --r;
            }
        }
        cout << edges.size() << endl;
        for(auto e : edges) cout << e[0] << " " << e[1] << endl;
    }
}
