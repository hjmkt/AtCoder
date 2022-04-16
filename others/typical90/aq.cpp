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
    ll rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    vvvll s(H, vvll(W, vll(4, 1000000)));
    rep(i, 4) s[rs-1][cs-1][i] = 0;
    deque<tuple<ll, ll, ll>> q;
    rep(i, 4) q.push_back({rs-1, cs-1, i});
    vvll dirs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    while(!q.empty()){
        auto [r, c, d] = q.front();
        q.pop_front();
        rep(i, 4){
            auto dir = dirs[i];
            ll nr = r + dir[0];
            ll nc = c + dir[1];
            if(nr<0 || nr>=H || nc<0 || nc>=W) continue;
            if(S[nr][nc]=='#') continue;
            ll t = d==i? s[r][c][d] : (s[r][c][d]+1);
            if(s[nr][nc][i]<=t) continue;
            s[nr][nc][i] = t;
            q.push_back({nr, nc, i});
        }
    }
    ll ans = *min_element(all(s[rt-1][ct-1]));
    cout << ans << endl;
}
