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

    ll H, W, N;
    cin >> H >> W >> N;

    vvll dxy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    ll di = 0;

    vector<string> S(H, string(W, '.'));
    ll x = 0, y = 0;
    rep(i, N){
        char c = S[y][x];
        if(c=='.'){
            S[y][x] = '#';
            di = (di+1)%4;
        }
        else{
            S[y][x] = '.';
            di = (di+3)%4;
        }
        x = (x+dxy[di][1]+W)%W;
        y = (y+dxy[di][0]+H)%H;
    }
    rep(i, H) cout << S[i] << endl;
}
