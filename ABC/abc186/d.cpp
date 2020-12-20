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

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    sort(all(A));
    vll s(N-1, 0);
    ll last = A[0];
    rep(i, N-1){
        s[i] = A[i+1]-last;
        last = A[i+1];
    }
    ll t = 0, r = 0;
    rep(i, N-1){
        r += s[i];
        t += r;
    }
    ll a = 0;
    rep(i, N-1){
        a += t;
        t -= s[i]*(N-1-i);
    }
    cout << a << endl;
}
