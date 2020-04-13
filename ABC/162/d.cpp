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

int main(){
    cout << setprecision(20);

    ll N;
    cin >> N;
    string S;
    cin >> S;

    vll rs(N, 0), gs(N, 0), bs(N, 0);
    irep(i, N){
        rs[i] = rs[min(i+1, N-1)];
        gs[i] = gs[min(i+1, N-1)];
        bs[i] = bs[min(i+1, N-1)];
        if(S[i]=='R') ++rs[i];
        else if(S[i]=='G') ++gs[i];
        else if(S[i]=='B') ++bs[i];
    }

    ll total = 0;
    rep(i, N){
        if(S[i]=='R'){
            REP(j, i+1, N){
                if(S[j]=='G') total += bs[j] - (2*j-i<N&&S[2*j-i]=='B'? 1 : 0);
                else if(S[j]=='B') total += gs[j] - (2*j-i<N&&S[2*j-i]=='G'? 1 : 0);
            }
        }
        else if(S[i]=='G'){
            REP(j, i+1, N){
                if(S[j]=='B') total += rs[j] - (2*j-i<N&&S[2*j-i]=='R'? 1 : 0);
                else if(S[j]=='R') total += bs[j] - (2*j-i<N&&S[2*j-i]=='B'? 1 : 0);
            }
        }
        else{
            REP(j, i+1, N){
                if(S[j]=='R') total += gs[j] - (2*j-i<N&&S[2*j-i]=='G'? 1 : 0);
                else if(S[j]=='G') total += rs[j] - (2*j-i<N&&S[2*j-i]=='R'? 1 : 0);
            }
        }
    }
    cout << total << endl;
}
