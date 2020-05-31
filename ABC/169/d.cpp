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

    ll N;
    cin >> N;

    if(N==1){
        cout << 0 << endl;
    }
    else{
        unordered_map<ll, ll> m;
        function<void(ll)> solve = [&](ll n){
            if(n==1) return;
            bool flag = false;
            for(ll k=2; k*k<=n; ++k){
                if(n%k==0){
                    solve(k);
                    solve(n/k);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                if(m.find(n)!=m.end()) ++m[n];
                else m[n] = 1;
            }
        };
        solve(N);

        ll total = 0;
        for(auto it : m){
            ll e = it.second;
            ll cnt = 1;
            while(e>0){
                e -= cnt;
                if(cnt+1>e) break;
                ++cnt;
            }
            total += cnt;
        }
        cout << total << endl;
    }
}
