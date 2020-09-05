#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()

ll pow_mod(ll n, ll m, ll mod){
    ll a = 1;
    while(m>0){
        if(m&1) a = a*n % mod;
        n = n*n % mod;
        m >>= 1;
    }
    return a;
}

int main(){
    string s;
    cin >> s;
    ll n = s.length();
    vll t;
    ll l = 0;
    while(l<n){
        ll count = 1;
        char c = s[l];
        REP(i, l+1, n){
            if(s[i]==c) ++count;
            else break;
        }
        if(count>=4){
            count = (count/2) * 2;
            if(c=='L'){
                t.push_back(-count/2);
                t.push_back(-count/2);
            }
            else{
                t.push_back(count/2);
                t.push_back(count/2);
            }
        }
        else{
            rep(i, count){
                t.push_back(c=='L'? -1 : 1);
            }
        }
        l += count;
    }
    vll t1(t.size());
    vll t2(t.size());
    rep(i, t.size()){
        t1[i] = abs(t[i]);
        t2[i] = abs(t[i]);
    }
    rep(i, 4){
        rep(j, t.size()){
            ll count = 0;
            if(j>0 && t[j-1]>0){
                count += t1[j-1];
            }
            if(j+1<t.size() && t[j+1]<0){
                count += t1[j+1];
            }
            t2[j] = count;
        }
        rep(j, t.size()){
            t1[j] = t2[j];
        }
    }
    vll g;
    rep(i, t.size()){
        if(i>0 && t[i-1]*t[i]<0){
            g.push_back(t2[i]);
        }
        else if(i+1<t.size() && t[i]*t[i+1]<0){
            g.push_back(t2[i]);
        }
    }

    ll last = 0;
    rep(i, n){
        if(i>0 && s[i]!=s[i-1]){
            cout << g[last] << " ";
            ++last;
        }
        else if(i+1<n && s[i]!=s[i+1]){
            cout << g[last] << " ";
            ++last;
        }
        else{
            cout << 0 << " ";
        }
    }
    cout << endl;
}
