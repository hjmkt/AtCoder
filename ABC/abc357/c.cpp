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

    ll N;
    cin >> N;

    function<vector<string>(ll)> f = [&](ll n){
        if(n==0) return vector<string>{"#"};
        auto prev = f(n-1);
        ll size = prev.size();
        vector<string> res(size*3, string(size*3, '.'));
        rep(r, 3) rep(c, 3){
            if(r==1 && c==1) continue;
            rep(i, size) rep(j, size) res[r*size+i][c*size+j] = prev[i][j];
        }
        return res;
    };
    auto ans = f(N);
    for(auto s : ans) cout << s << endl;
}
