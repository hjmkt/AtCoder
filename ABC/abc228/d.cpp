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
    ll N = 1ll<<20;
    
    set<ll> s;
    rep(i, N) s.insert(i);
    vll A(N, -1);

    rep(i, Q){
        ll t, x;
        cin >> t >> x;
        if(t==1){
            ll h = x;
            auto it = s.lower_bound(h%N);
            ll d = 0;
            if(it==s.end()){
                it = s.lower_bound(0);
                h += N - h%N;
                d = *it;
            }
            else{
                d = *it - h%N;
            }
            h += d;
            A[h%N] = x;
            s.erase(h%N);
        }
        else{
            cout << A[x%N] << endl;
        }
    }
}
