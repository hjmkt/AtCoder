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
    ll Si, Sj;
    cin >> Si >> Sj;
    vector<string> C(H);
    rep(i, H) cin >> C[i];
    string X;
    cin >> X;

    ll y = Si-1, x = Sj-1;
    for(char c : X){
        if(c=='U'){
            if(y>0 && C[y-1][x]=='.') --y;
        }
        else if(c=='D'){
            if(y<H-1 && C[y+1][x]=='.') ++y;
        }
        else if(c=='L'){
            if(x>0 && C[y][x-1]=='.') --x;
        }
        else if(c=='R'){
            if(x<W-1 && C[y][x+1]=='.') ++x;
        }
    }
    cout << y+1 << " " << x+1 << endl;
}
