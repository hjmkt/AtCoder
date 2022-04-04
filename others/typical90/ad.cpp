#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

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

    ll N, K;
    cin >> N >> K;

    vector<bool> is_prime(N+1, true);
    vll primes;
    REP(i, 2, N+1){
        if(is_prime[i]){
            primes.push_back(i);
            for(ll j=i+i; j<N+1; j+=i) is_prime[j] = false;
        }
        else continue;
    }

    vll count(N+1, 0);
    for(ll prime : primes){
        for(ll n=prime; n<=N; n+=prime) ++count[n];
    }
    ll ans = 0;
    rep(i, N+1) if(count[i]>=K) ++ans;
    cout << ans << endl;
}
