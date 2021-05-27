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

    ll N, L, K;
    cin >> N >> L >> K;
    vll A(N);
    rep(i, N) cin >> A[i];
    vll B;
    ll last = 0;
    rep(i, N){
        B.push_back(A[i]-last);
        last = A[i];
    }
    B.push_back(L-A[N-1]);

    ll left = 1, right = L;
    while(left<right){
        ll mid = (left+right+1)/2;
        ll count = 0;
        ll current = 0;
        rep(i, N+1){
            current += B[i];
            if(current>=mid){
                ++count;
                current = 0;
            }
        }
        if(count>=K+1) left = mid;
        else right = mid-1;
    }
    cout << left << endl;
}
