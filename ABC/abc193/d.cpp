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

ll pow(ll a, ll b){
    ll n = 1;
    rep(i, b) n *= a;
    return n;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll K;
    cin >> K;
    string S, T;
    cin >> S >> T;

    vvll r(9, vll(9, 0));
    vll ts(9, 0), as(9, 0);
    rep(i, (ll)S.length()-1){
        ++ts[S[i]-'1'];
        ++as[T[i]-'1'];
    }
    double p = 0;
    rep(i, 9){
        rep(j, 9){
            ll t = 0, a = 0;
            rep(k, 9){
                t += pow(10, ts[k]+(k==i? 1:0)) * (k+1);
                a += pow(10, as[k]+(k==j? 1:0)) * (k+1);
            }
            double r = 0;
            if(i==j){
                r = (double)(K-ts[i]-as[i]) / (9*K-8) * (K-ts[i]-as[i]-1) / (9*K-9);
            }
            else{
                r = (double)(K-ts[i]-as[i]) / (9*K-8) * (K-ts[j]-as[j]) / (9*K-9);
            }
            if(t>a) p += r;
        }
    }
    cout << p << endl;
}
