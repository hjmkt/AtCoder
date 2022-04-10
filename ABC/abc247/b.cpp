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
    vector<string> s(N), t(N);
    rep(i, N) cin >> s[i] >> t[i];

    map<string, ll> m;
    rep(i, N){
        if(s[i]==t[i]){
            ++m[s[i]];
        }
        else{
            ++m[s[i]];
            ++m[t[i]];
        }
    }
    set<string> u;
    rep(i, N){
        if(m[s[i]]>=2 && m[t[i]]>=2){
            cout << "No" << endl;
            return 0;
        }
        if(m[s[i]]>=2){
            if(u.find(t[i])!=u.end()){
                cout << "No" << endl;
                return 0;
            }
            u.insert(t[i]);
        }
        else if(m[t[i]]>=2){
            if(u.find(s[i])!=u.end()){
                cout << "No" << endl;
                return 0;
            }
            u.insert(s[i]);
        }
    }
    cout << "Yes" << endl;
}
