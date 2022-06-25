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
    string S;
    cin >> S;
    vll W(N);
    rep(i, N) cin >> W[i];

    vector<pair<ll, ll>> v(N);
    rep(i, N){
        v[i] = {(ll)(S[i]-'0'), W[i]};
    }
    sort(all(v), [](auto l, auto r){ return l.second<r.second; });
    ll pred = 0, gt = 0;
    rep(i, N){
        if(S[i]=='0') ++gt;
    }
    ll ans = N - gt;
    ll childs = gt;
    gt = 0;
    rep(i, N){
        ll w = v[i].second;
        while(w==v[i].second){
            ++pred;
            if(v[i].first==0) ++gt;
            ++i;
            if(i>=N) break;
        }
        ll n = gt + (N-childs-(i-gt));
        ans = max(ans, n);
        --i;
    }
    cout << ans << endl;
}
