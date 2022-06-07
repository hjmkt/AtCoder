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

    ll H, W;
    cin >> H >> W;
    vector<string> c(H);
    rep(i, H) cin >> c[i];

    queue<tuple<vector<string>, ll, ll, ll>> q;
    rep(i, H) rep(j, W){
        if(c[i][j]=='.'){
            vector<string> t = c;
            t[i][j] = '*';
            q.push({t, i, j, 0});
        }
    }
    ll ans = 0;
    vector<pair<ll, ll>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while(!q.empty()){
        auto [m, y, x, n] = q.front();
        for(auto [dy, dx] : dirs){
            ll ny = y + dy, nx = x + dx;
            if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
            if(m[ny][nx]=='.'){
                vector<string> t = m;
                t[ny][nx] = '#';
                q.push({t, ny, nx, n+1});
            }
            else if(m[ny][nx]=='*' && n>=2){
                ans = max(ans, n+1);
            }
        }
        q.pop();
    }
    if(ans>0) cout << ans << endl;
    else cout << -1 << endl;
}
