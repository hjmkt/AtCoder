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

    ll T;
    cin >> T;
    rep(t, T){
        ll N;
        cin >> N;
        string s = to_string(N);
        ll l = s.length();
        ll m = stoll(string(l-1, '9'));
        REP(i, 2, l+1){
            if(l%i==0){
                ll n = l / i;
                string x = s.substr(0, n);
                string y = "";
                rep(_, i) y += x;
                ll r = stoll(y);
                if(r<=N){
                    m = max(m, r);
                    continue;
                }
                if(x.back()=='0'){
                    r = stoll(x);
                    --r;
                    x = to_string(r);
                    y = "";
                    rep(_, i) y += x;
                    r = stoll(y);
                    m = max(m, r);
                    continue;
                }
                x[n-1] = x[n-1] - 1;
                y = "";
                rep(_, i) y += x;
                r = stoll(y);
                m = max(m, r);
            }
        }
        cout << m << endl;
    }
}
