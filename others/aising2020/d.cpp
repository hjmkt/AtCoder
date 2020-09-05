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


ll pow_mod(ll n, ll m, ll mod=1000000007){
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
    string X;
    cin >> X;

    ll bits = 0;
    for(char c : X){
        if(c=='1') ++bits;
    }

    auto smod = [](string m, ll n){
        if(n==0) return 0ll;
        while(m.length()>61){
            ll offset = m.length() - 61;
            string b0 = m.substr(0, 61);
            string b1 = m.substr(61);
            ll t = stoll(b0, nullptr, 2);
            t %= n;
            if(t>0){
                stringstream ss;
                while(t>0){
                    ss << to_string(t&1);
                    t >>= 1;
                }
                string s = ss.str();
                reverse(all(s));
                m = s + b1;
            }
            else{
                m = b1;
            }
        }
        return stoll(m, nullptr, 2) % n;
    };

    ll t0 = smod(X, bits-1);
    ll t1 = smod(X, bits);
    ll t2 = smod(X, bits+1);

    rep(i, N){
        ll t = 0;
        ll count = 0;
        if(X[i]=='1'){
            t = t0;
            if(bits>1){
                count = 1;
                t = (t-pow_mod(2, N-i-1, bits-1)+(bits-1))%(bits-1);
            }
            else t = 0;
        }
        else{
            t = t2;
            t = (t+pow_mod(2, N-i-1, bits+1))%(bits+1);
            count = 1;
        }
        while(t>0){
            ll bits = bitset<64>(t).count();
            t %= bits;
            ++count;
        }
        cout << count << endl;
    }
}

