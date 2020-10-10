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

    ll T;
    cin >> T;

    ll M = 1000000007;

    rep(t, T){
        ll N, A, B;
        cin >> N >> A >> B;

        if(A+B>N) cout << 0 << endl;
        else{
            if(A<B) swap(A, B);
            ll a = (N-A+1)*(N-A+1) % M;
            ll b = (N-B+1)*(N-B+1) % M;
            ll count = a*b % M;
            // (N-A-l1+1)(N-A-l2+1)*4 for l=1..(B-1)
            ll d = (N-A+1)*(N-A+1)*4 % M;
            d = (d+B*B-B*(N-A+1)*4) % M;
            d = d*(B-1) % M;
            d = d*(B-1) % M;
            count = ((count-d)%M+M) % M;

            ll d1 = (N-A+1)*(N-A+1) % M;
            ll d2 = (A-B+1)*(A-B+1) % M;
            count = (((count-d1*d2%M)%M+M)) % M;

            // (N-A-l+1)(N-A+1)*(A-B+1)*4 for l=1..(B-1)
            d1 = (N-A+1)*(N-A+1) % M;
            d1 = d1*(B-1) % M;
            d2 = B * (B-1) / 2 % M;
            d2 = d2*(N-A+1) % M;
            d = (d1-d2+M) % M;
            d = d * (A-B+1) % M;
            count = ((count-d*4)%M+M) % M;

            cout << count << endl;
        }
    }
}
