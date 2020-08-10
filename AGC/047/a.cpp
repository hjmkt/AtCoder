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
    vector<double> A(N);
    rep(i, N) cin >> A[i];
    vll B(N, 0);
    rep(i, N) B[i] = A[i] * 1000000000 + 0.5;
    vll d2(N, 0), d5(N, 0);
    rep(i, N){
        while(B[i]>0 && B[i]%2==0){
            B[i] /= 2;
            ++d2[i];
        }
        while(B[i]>0 && B[i]%5==0){
            B[i] /= 5;
            ++d5[i];
        }
    }
    ll total = 0;
    vvll t25(19, vll(19, 0));
    rep(i, N){
        total += t25[min(d2[i], 18ll)][min(d5[i], 18ll)];
        REP(j, max(0ll, 18-d2[i]), 19){
            REP(k, max(0ll, 18-d5[i]), 19){
                ++t25[j][k];
            }
        }
    }
    cout << total << endl;
}
