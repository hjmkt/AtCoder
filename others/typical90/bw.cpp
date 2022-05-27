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
    deque<ll> q = {N};
    vll factors;
    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        bool found = false;
        ll ub = sqrt((double)n) + 2;
        REP(i, 2, ub){
            if(n%i==0 && i!=n){
                q.push_back(i);
                q.push_back(n/i);
                found = true;
                break;
            }
        }
        if(!found){
            factors.push_back(n);
        }
    }
    ll n = factors.size() - 1;
    ll ans = 0;
    while(n>0){
        n /= 2;
        ++ans;
    }
    cout << ans << endl;
}
