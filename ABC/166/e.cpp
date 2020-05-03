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
    vll A(N);
    rep(i, N) cin >> A[i];

    unordered_map<ll, ll> s1, s2;
    ll count = 0;
    rep(i, N){
        ll k1 = A[i] + i;
        ll k2 = i - A[i];
        ll n1 = i - A[i];
        ll n2 = i + A[i];
        if(s1.find(k1)!=s1.end()) count += s1[k1];
        if(s2.find(k2)!=s2.end()) count += s2[k2];
        if(s1.find(n1)==s1.end()) s1[n1] = 1;
        else ++s1[n1];
        if(s2.find(n2)==s2.end()) s2[n2] = 1;
        else ++s2[n2];
    }
    cout << count << endl;
}
