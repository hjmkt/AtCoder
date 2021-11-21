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

ll pow_mod(ll n, ll m, ll mod=7){
    ll a = 1;
    while(m>0){
        if(m&1) a = a*n % mod;
        n = n*n % mod;
        m >>= 1;
    }
    return a;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;

    ll m = 1;
    while((m+1)*(m+2)/2<=N) ++m;
    ll r = N - m;
    string s1(m, '7'), s2(r, '7');

    vll ms;
    while(N>0){
        ll m = 1;
        while((m+1)*(m+2)/2<=N) ++m;
        ms.push_back(m);
        N -= m*(m+1)/2;
    }

    vll p(ms.size()-1, 1);
    while(true){
        bool ok = true;
        rep(i, p.size()){
            ll t = p[i];
            REP(j, i+1, p.size()){
                t = (t*pow_mod(10, ms[j]+1) + p[j]) % 7;
                if(t==0){
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok){
            string s(ms[0], '7');
            REP(i, 1, ms.size()){
                s += (char)('0'+p[i-1]);
                s += string(ms[i], '7');
            }
            cout << s << endl;
            return 0;
        }
        rep(i, p.size()){
            if(p[i]<9){
                ++p[i];
                if(p[i]==7) ++p[i];
                break;
            }
            else if(i==p.size()-1) break;
            else{
                p[i] = 1;
            }
        }
    }
    cout << "" << endl;
}
