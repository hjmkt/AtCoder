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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N, Q, X;
    cin >> N >> Q >> X;
    vll W(N);
    rep(i, N) cin >> W[i];
    vll K(Q);
    rep(i, Q) cin >> K[i];

    ll total = 0;
    rep(i, N) total += W[i];

    vector<pair<ll, ll>> v(N);
    vll w;
    rep(_, 2) rep(i, N) w.push_back(W[i]);
    ll left = 0, right = -1;
    ll r = total*(X/total);
    rep(i, N){
        if(X%total==0){
            v[i] = {0, r};
            continue;
        }
        while(r+w[right+1]<X || left>right){
            r += w[++right];
        }
        if(r<X) r += w[++right];
        v[i] = {right-left+1, r};
        r -= w[left++];
    }
    ll c0 = -1, c1 = -1;
    vll checked(N, -1);
    ll cur = 0;
    ll count = 0;
    vll indices;
    while(true){
        checked[cur] = count;
        indices.push_back(cur);
        ll next = (cur + v[cur].first) % N;
        if(checked[next]>=0){
            c0 = checked[next];
            c1 = count;
            break;
        }
        cur = next;
        ++count;
    }
    rep(i, Q){
        if(K[i]-1<=c0){
            ll idx = indices[K[i]-1];
            ll n = v[idx].first + X/total*N;
            cout << n << endl;
        }
        else{
            ll idx = c0;
            ll k = K[i] - 1 - c0;
            k %= (c1-c0+1);
            idx += k;
            idx = indices[idx];
            ll n = v[idx].first + X/total*N;
            cout << n << endl;
        }
    }
}
