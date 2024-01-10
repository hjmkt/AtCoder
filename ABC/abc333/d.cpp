#include <bits/stdc++.h>
#include <climits>

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
    vector<uset<ll>> e(N);
    rep(i, N-1){
        ll u, v;
        cin >> u >> v;
        e[u-1].insert(v-1);
        e[v-1].insert(u-1);
    }
    if(e[0].size()==1) cout << 1 << endl;
    else{
        uset<ll> neighbors;
        for(auto n : e[0]){
            neighbors.insert(n);
        }
        uset<ll> visited;
        visited.insert(0);
        for(auto n : neighbors){
            e[n].erase(0);
            e[0].erase(n);
            visited.insert(n);
        }
        ll ans = 1;
        ll max_count = 0;
        for(auto n : neighbors){
            ll count = 0;
            queue<ll> q;
            q.push(n);
            visited.insert(n);
            while(!q.empty()){
                ll u = q.front();
                q.pop();
                ++count;
                for(auto v : e[u]){
                    if(visited.find(v)==visited.end()) q.push(v);
                    visited.insert(v);
                }
            }
            ans += count;
            max_count = max(max_count, count);
        }
        ans -= max_count;
        cout << ans << endl;
    }
}
