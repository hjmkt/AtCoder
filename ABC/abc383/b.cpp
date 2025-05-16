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

    ll H, W, D;
    cin >> H >> W >> D;
    string S[H];
    rep(i, H) cin >> S[i];

    ll ans = 0;
    rep(i, H*W) {
        ll h1 = i / W;
        ll w1 = i % W;
        if (S[h1][w1] == '#') continue;
        REP(j, i+1, H*W) {
            ll h2 = j / W;
            ll w2 = j % W;
            if (S[h2][w2] == '#') continue;
            ll count = 0;
            rep(h, H) {
                rep(w, W) {
                    if (S[h][w] == '#') continue;
                    ll md1 = abs(h1 - h) + abs(w1 - w);
                    ll md2 = abs(h2 - h) + abs(w2 - w);
                    if(md1<=D || md2<=D) {
                        ++count;
                    }
                }
            }
            ans = max(ans, count);
        }
    }
    cout << ans << endl;
}
