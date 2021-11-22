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

    ll sum = 0;
    vll S(N, 0);
    rep(i, N){
        sum += A[i];
        S[i] = sum;
    }
    if(sum!=0){
        cout << -1 << endl;
        return 0;
    }

    // -a[n-1]+2*a[n]-a[n+1]==-A[n], a>=0
    // b[n] = a[n+1]-a[n]
    // b[n] - b[n-1] = A[n]
    // b[n] - b[0] = sum(k<=n) A[k]
    // b[0] = b[n] - sum(k<=n) A[k]
    // N*b[0] = sum(l<N) b[l] - sum(l<N) sum(k<=l) A[l]

    vll T(N, 0);
    sum = 0;
    rep(i, N){
        sum += S[i];
        T[i] = sum;
    }

    vll a(N, 0), b(N, 0);
    b[0] = -T[N-1];
    if(b[0]%N!=0){
        cout << -1 << endl;
        return 0;
    }
    b[0] /= N;

    REP(i, 1, N) b[i] = b[0] + S[i];
    rep(i, 300){
        bool ok = true;
        a[0] = i;
        REP(j, 1, N){
            a[j] = a[j-1] + b[j-1];
            if(a[j]<0){
                ok = false;
                break;
            }
        }
        if(ok){
            ll ans = 0;
            rep(j, N) ans += a[j];
            cout << ans << endl;
            return 0;
        }
    }
}
