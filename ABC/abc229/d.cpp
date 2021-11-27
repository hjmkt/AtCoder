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

    string S;
    cin >> S;
    ll K;
    cin >> K;

    vll sum(S.length()+1, 0);
    ll s = 0;
    rep(i, S.length()){
        if(S[i]=='.') ++s;
        sum[i+1] = s;
    }

    ll ans = 0;
    rep(i, S.length()){
        ll empties = sum[i+1];
        ll low = 0, high = i;
        while(low<high){
            ll mid = (low+high+1) / 2;
            if(empties-sum[mid]<=K){
                high = mid - 1;
                ans = max(ans, i+1-mid);
            }
            else{
                low = mid;
            }
        }
        if(empties-sum[low]<=K) ans = max(ans, i+1-low);
    }
    cout << ans << endl;
}
