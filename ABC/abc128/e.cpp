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
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, Q;
    cin >> N >> Q;

    auto comp = [](vll& l, vll& r){
        if(l[0]>r[0]) return true;
        else if(l[0]==r[0] && l[2]>r[2]) return true;
        else return false;
    };
    priority_queue<vll, vvll, decltype(comp)> exq(comp);

    rep(i, N){
        ll s, t, x;
        cin >> s >> t >> x;
        exq.push({s-x, x, 1});
        exq.push({t-x, x, -1});
    }

    priority_queue<vll, vvll, decltype(comp)> dq(comp);
    rep(i, Q){
        ll d;
        cin >> d;
        dq.push({d, i});
    }

    multiset<ll> sx;
    vll ans(Q);

    while(!dq.empty()){
        auto dv = dq.top();
        ll d = dv[0], idx = dv[1];
        dq.pop();
        while(!exq.empty()){
            auto exv = exq.top();
            ll e = exv[0], x = exv[1], etype = exv[2];
            if(e<=d){
                if(etype==1) sx.insert(x);
                else sx.erase(x);
                exq.pop();
            }
            else break;
        }
        if(sx.size()==0){
            ans[idx] = -1;
        }
        else{
            ll x = *sx.begin();
            ans[idx] = x;
        }
    }

    rep(i, Q) cout << ans[i] << endl;
}
