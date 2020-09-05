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

    ll K;
    cin >> K;

    ll count = 0;
    unordered_map<ll, ll> m;
    ll n = 1;
    ll ord = 1;
    ll last = 0;
    while(true){
        if(n>=ord*10) ord *= 10;
        ll sub = n % ord;
        ll valid = true;
        if(sub<ord/10){
            ll msd = sub;
            while(msd/10>0) msd /= 10;
            if(msd>=2) valid = false;
        }
        if(valid){
            if(n<10){
                ++count;
                m[last] = n;
                last = n;
            }
            else{
                ll d1 = n/ord, d2 = sub%ord*10/ord;
                if(abs(d1-d2)<=1){
                    ++count;
                    m[last] = n;
                    m[n] = -1;
                    last = n;
                }
            }
        }
        if(count==K){
            cout << n << endl;
            return 0;
        }
        if(m.find(sub)==m.end()) ++n;
        else if(m[sub]==-1) n = 10*ord;
        else n = n/ord*ord + m[sub];
    }
}
