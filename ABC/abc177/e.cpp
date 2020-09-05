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


ll gcd(ll n, ll m){
    while(true){
        if(n<m) swap(n, m);
        if(!m) break;
        n %= m;
    }
    return n;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];
    vll B = A;

    vector<bool> prime(1000001, true);
    prime[0] = prime[1] = false;
    rep(i, 1000001){
        if(prime[i]){
            for(ll j=i+i; j<1000001; j+=i){
                prime[j] = false;
            }
        }
    }

    bool pc = true;
    REP(i, 2, 1002){
        if(!prime[i]) continue;
        bool flag = false;
        bool valid = true;
        rep(j, N){
            if(A[j]%i==0){
                while(A[j]%i==0) A[j] /= i;
                if(flag){
                    valid = false;
                    break;
                }
                else flag = true;
            }
        }
        if(!valid){
            pc = false;
            break;
        }
    }
    if(pc){
        vector<bool> appeared(1000001, false);
        rep(i, N){
            if(A[i]>=2 && appeared[A[i]]){
                pc = false;
                break;
            }
            appeared[A[i]] = true;
        }
    }

    if(pc) cout << "pairwise coprime" << endl;
    else{
        ll g = B[0];
        REP(i, 1, N) g = gcd(g, B[i]);
        if(g==1) cout << "setwise coprime" << endl;
        else cout << "not coprime" << endl;
    }
}
