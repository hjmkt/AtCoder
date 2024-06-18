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

    ll L, R;
    cin >> L >> R;
    vector<pair<ll, ll>> ans;
    for(ll left=L; left<R;){
        ll tmp = left;
        ll p = 0;
        while(tmp%2==0 && left+(1ll<<(p+1))<=R){
            tmp /= 2;
            ++p;
        }
        ans.push_back({left, left+(1ll<<p)});
        left += 1ll<<p;
    }
    cout << ans.size() << endl;
    for(auto a : ans){
        cout << a.first << " " << a.second << endl;
    }
}
