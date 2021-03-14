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
    vll A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    ll ma1 = LLONG_MAX;
    ll idxa1 = -1;
    ll ma2 = LLONG_MAX;
    ll idxa2 = -1;
    ll mb1 = LLONG_MAX;
    ll idxb1 = -1;
    ll mb2 = LLONG_MAX;
    ll idxb2 = -1;
    ll m = LLONG_MAX;
    ll idx = -1;

    rep(i, N){
        if(A[i]<ma1){
            idxa2 = idxa1;
            ma2 = ma1;
            idxa1 = i;
            ma1 = A[i];
        }
        else if(A[i]<ma2){
            idxa2 = i;
            ma2 = A[i];
        }
        if(B[i]<mb1){
            idxb2 = idxb1;
            mb2 = mb1;
            idxb1 = i;
            mb1 = B[i];
        }
        else if(B[i]<mb2){
            idxb2 = i;
            mb2 = B[i];
        }
        ll c = A[i]+B[i];
        if(c<m){
            m = c;
            idx = i;
        }
    }

    if(idxa1==idxb1){
        ll t = min(max(ma1, mb2), max(ma2, mb1));
        cout << min(t, m) << endl;
    }
    else{
        cout << min(max(ma1, mb1), m) << endl;
    }
}
