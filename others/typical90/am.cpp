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
    vll a(N-1), b(N-1);
    rep(i, N-1){
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }

    vector<uset<ll>> t(N);
    rep(i, N-1){
        t[a[i]].insert(b[i]);
        t[b[i]].insert(a[i]);
    }

    vector<pair<ll, ll>> d(N, {0, 0});
    function<pair<ll, ll>(ll, ll)> dist = [&](ll cur, ll prev){
        ll n = 1, s = 0;
        for(ll c : t[cur]){
            if(c==prev) continue;
            auto p = dist(c, cur);
            n += p.first;
            s += p.second + p.first;
        }
        d[cur] = pair<ll, ll>(n, s);
        return d[cur];
    };
    dist(0, -1);

    ll ans = 0;
    function<void(ll, ll)> solve = [&](ll cur, ll prev){
        ans += d[cur].second;
        vector<pair<ll, ll>> v;
        ll sum = 0;
        for(ll c : t[cur]){
            if(c==prev) continue;
            solve(c, cur);
            v.push_back({d[c].first, d[c].second+d[c].first});
            sum += d[c].first;
        }
        rep(i, v.size()){
            ans += v[i].second*(sum-v[i].first);
        }
    };
    solve(0, -1);
    cout << ans << endl;
}
