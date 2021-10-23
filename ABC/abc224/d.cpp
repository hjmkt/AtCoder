#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

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

    ll M;
    cin >> M;
    vll u(M), v(M);
    rep(i, M) cin >> u[i] >> v[i];
    vll p(8);
    rep(i, 8) cin >> p[i];

    vector<unordered_set<ll>> e(9);
    rep(i, M){
        e[u[i]-1].insert(v[i]-1);
        e[v[i]-1].insert(u[i]-1);
    }

    unordered_map<ll, ll> s;
    function<bool(const ll&, const ll&)> comp = greater<ll>();
    auto c = [&comp](tuple<ll, ll> l, tuple<ll, ll> r){ return comp(get<0>(l), get<0>(r)); };
    priority_queue<tuple<ll, ll>, vector<tuple<ll, ll>>, decltype(c)> q(c);

    ll start = 0;
    rep(i, 8) start += (p[i]-1) << (4*i);
    vector<bool> occ(9, false);
    rep(i, 8) occ[p[i]-1] = true;
    rep(i, 9) {
        if(!occ[i]){
            start += i << 4*8;
        }
    }

    ll target = 0;
    rep(i, 8) target += i << (4*i);
    target += 8ll << 4*8;

    if(start==target){
        cout << 0 << endl;
        return 0;
    }

    q.push({0, start});

    while(!q.empty()){
        auto [d, n] = q.top();
        q.pop();
        if(s[n]>0) continue;
        s[n] = d;
        ll space = (n >> 4*8) & 0xf;
        for(auto t : e[space]){
            ll m = n;
            ll r = 0;
            rep(i, 8){
                if(((m>>(4*i))&0xf)==t){
                    r = i;
                    break;
                }
            }
            m &= ~(0xfll << 4*8);
            m &= ~(0xfll << 4*r);
            m |= t << 4*8;
            m |= space << 4*r;
            if(s[m]>0) continue;
            q.push({d+1, m});
        }
    }

    if(s[target]>0) cout << s[target] << endl;
    else cout << -1 << endl;
}
