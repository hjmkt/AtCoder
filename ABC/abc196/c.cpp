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

ll npow(ll n, ll m){
    ll t = 1;
    while(m>0){
        t *= n;
        --m;
    }
    return t;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;

    string n = to_string(N);
    if(n.length()%2==0){
        string s1 = n.substr(0, n.length()/2);
        ll sn1 = stoll(s1);
        string s2 = n.substr(n.length()/2);
        ll sn2 = stoll(s2);
        ll l = n.length()/2-1;
        ll ans = sn1-npow(10, l)+1;
        if(sn1>sn2) --ans;
        REP(t, 1, l+1){
            ans += 9*npow(10, t-1);
        }
        cout << ans << endl;
    }
    else{
        ll l = n.length()/2;
        ll ans = 0;
        REP(t, 1, l+1){
            ans += 9*npow(10, t-1);
        }
        cout << ans << endl;
    }
}
