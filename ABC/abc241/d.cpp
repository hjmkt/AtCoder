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

    ll Q;
    cin >> Q;
    multiset<ll> s;
    rep(_, Q){
        ll q;
        cin >> q;
        s.insert(LLONG_MAX);
        if(q==1){
            ll x;
            cin >> x;
            s.insert(x);
        }
        else if(q==2){
            ll x, k;
            cin >> x >> k;
            auto it = s.upper_bound(x);
            bool ok = true;
            rep(i, k){
                if(it==s.begin()){
                    ok = false;
                    break;
                }
                --it;
            }
            if(ok) cout << *it << endl;
            else cout << -1 << endl;
        }
        else{
            ll x, k;
            cin >> x >> k;
            auto it = s.lower_bound(x);
            bool ok = true;
            rep(i, k-1){
                if(it==s.end()){
                    ok = false;
                    break;
                }
                ++it;
            }
            if(ok){
                if(it!=s.end() && *it<LLONG_MAX) cout << *it << endl;
                else cout << -1 << endl;
            }
            else cout << -1 << endl;
        }
    }
}
