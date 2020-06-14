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
    sort(all(A));

    unordered_set<ll> s;
    ll count = 0;
    rep(i, N){
        if(i>0 && A[i-1]==A[i]) continue;
        if(i<N-1 && A[i]==A[i+1]){
            for(ll n=A[i]; n<=1000000; n+=A[i]){
                s.insert(n);
            }
        }
        else{
            if(s.find(A[i])==s.end()) ++count;
            for(ll n=A[i]; n<=1000000; n+=A[i]){
                s.insert(n);
            }
        }
    }
    cout << count << endl;
}
