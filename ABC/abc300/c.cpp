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
    vector<string> C(H);
    rep(i, H) cin >> C[i];

    auto check = [&](ll n, ll y, ll x){
        if(y<n || y>=H-n || x<n || x>=W-n) return false;
        if(C[y][x]=='.') return false;
        REP(i, 1, n+1){
            if(C[y-i][x-i]=='.' || C[y-i][x+i]=='.' || C[y+i][x-i]=='.' || C[y+i][x+i]=='.') return false;
        }
        return true;
    };
    auto update = [&](ll n, ll y, ll x){
        C[y][x] = '.';
        REP(i, 1, n+1){
            C[y-i][x-i] = C[y-i][x+i] = C[y+i][x-i] = C[y+i][x+i] = '.';
        }
    };
    vll S(min(H, W), 0);
    REP(n, 1, (min(H, W)-1)/2+1){
        rep(y, H){
            rep(x, W){
                if(check(n, y, x) && !check(n+1, y, x)){
                    ++S[n-1];
                    update(n, y, x);
                }
            }
        }
    }
    rep(i, (ll)S.size()-1) cout << S[i] << " ";
    cout << S.back() << endl;
}
