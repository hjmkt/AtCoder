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

    ll N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    vll l(N, 0), r(N, 0), nl(N, 0), nr(N, 0);
    ll count = 0, last = 0;
    rep(i, N){
        l[i] = count;
        nl[i] = last;
        if(S[i]=='x') continue;
        l[i] = ++count;
        nl[i] = last = i;
        rep(j, C){
            ++i;
            if(i>=N) break;
            l[i] = count;
            nl[i] = last;
        }
    }
    count = 0;
    last = N-1;
    irep(i, N){
        r[i] = count;
        nr[i] = last;
        if(S[i]=='x') continue;
        r[i] = ++count;
        nr[i] = last = i;
        rep(j, C){
            --i;
            if(i<0) break;
            r[i] = count;
            nr[i] = last;
        }
    }

    rep(i, N){
        if(S[i]=='x') continue;
        if(i==0){
            ll t = i+1<N? r[i+1] : 0;
            if(t<K) cout << i+1 << endl;
        }
        else if(i==N-1){
            ll t = l[i-1];
            if(t<K) cout << i+1 << endl;
        }
        else{
            ll n1 = nl[i-1];
            ll n2 = nr[i+1];
            ll t = l[n1] + r[n2];
            if(t<K) cout << i+1 << endl;
            else if(t==K && n2-n1<=C && l[n1]>0 && r[n2]>0) cout << i+1 << endl;
        }
    }
}
