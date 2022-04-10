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

    ll Q;
    cin >> Q;

    deque<pair<ll, ll>> q;
    vll ans;
    rep(i, Q){
        ll t;
        cin >> t;
        if(t==1){
            ll x, c;
            cin >> x >> c;
            if(q.empty()){
                q.push_back({x, c});
            }
            else{
                auto p = q.back();
                if(p.first==x){
                    p.second += c;
                    q.pop_back();
                    q.push_back(p);
                }
                else{
                    q.push_back({x, c});
                }
            }
        }
        else{
            ll c;
            cin >> c;
            ll a = 0;
            while(c>0){
                auto p = q.front();
                if(c<=p.second){
                    a += p.first * c;
                    p.second -= c;
                    q.pop_front();
                    c = 0;
                    if(p.second>0) q.push_front(p);
                }
                else{
                    c -= p.second;
                    q.pop_front();
                    a += p.first * p.second;
                }
            }
            ans.push_back(a);
        }
    }
    if(ans.empty()) cout << endl;
    else for(ll a: ans) cout << a << endl;
}
