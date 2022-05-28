#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;
template<class T> using mset = multiset<T>;
template<class T, class U> using mmap = multimap<T, U>;
template<class T> using umset = unordered_multiset<T>;
template<class T, class U> using ummap = unordered_multimap<T, U>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

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

    ll N, A, B;
    cin >> N >> A >> B;

    if(A==1||B==1){
        cout << 0 << endl;
        return 0;
    }

    ll ans = N*(N+1) / 2;
    ll a = (N/A)*(N/A+1) / 2;
    ll b = (N/B)*(N/B+1) / 2;
    ll g = gcd(A, B);
    g = A*B / g;
    ll ab = (N/g)*(N/g+1) / 2;
    ans = ans - A*a - B*b + g*ab;
    cout << ans << endl;
}
