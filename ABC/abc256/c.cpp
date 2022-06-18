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

    vll h(3), w(3);
    rep(i, 3) cin >> h[i];
    rep(i, 3) cin >> w[i];

    ll ans = 0;
    REP(i0, 1, min(h[0]-2, w[0]-2)+1){
        REP(i1, 1, min(h[0]-i0-1, w[1]-2)+1){
            ll i2 = h[0] - i0 - i1;
            REP(i3, 1, min(h[1]-2, w[0]-i0-1)+1){
                REP(i4, 1, min(h[1]-i3-1, w[1]-i1-1)+1){
                    ll i5 = h[1] - i3 - i4;
                    if(i5>=1 && i5<=w[2]-i2-1){
                        ll i6 = w[0] - i0 - i3;
                        ll i7 = w[1] - i1 - i4;
                        ll i8 = w[2] - i2 - i5;
                        if(i6>=1 && i7>=1 && i8>=1 && i6+i7+i8==h[2]) ++ans;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
