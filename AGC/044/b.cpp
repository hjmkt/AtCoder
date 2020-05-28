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

    ll N;
    cin >> N;
    vll P(N*N, 0);
    rep(i, N*N) cin >> P[i];

    vll d(N*N, 0), s(N*N, 0);
    rep(y, N) rep(x, N) d[y*N+x] = min({x, N-x-1, y, N-y-1});
    vvll dirs = vvll{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    ll total = 0;
    rep(i, N*N){
        ll p = P[i] - 1;
        s[p] = 1;
        queue<ll> q;
        q.push(p);
        total += d[p];
        while(!q.empty()){
            ll xy = q.front();
            ll x = xy%N, y = xy/N;
            q.pop();
            for(auto &dir : dirs){
                ll nx = x+dir[0], ny = y+dir[1];
                ll nxy = ny*N + nx;
                if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                if(d[nxy]>d[xy]+1 || (s[xy] && d[nxy]>d[xy])){
                    --d[nxy];
                    q.push(nxy);
                }
            }
        }
    }
    cout << total << endl;
}
