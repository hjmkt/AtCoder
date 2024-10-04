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

    ll a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    if(a>=d) swap(a, d);
    if(b>=e) swap(b, e);
    if(c>=f) swap(c, f);
    if(g>=j) swap(g, j);
    if(h>=k) swap(h, k);
    if(i>=l) swap(i, l);
    bool intersect_x = (a<g && g<d) || (a<j && j<d) || (g<a && a<j) || (g<d && d<j);
    bool intersect_y = (b<h && h<e) || (b<k && k<e) || (h<b && b<k) || (h<e && e<k);
    bool intersect_z = (c<i && i<f) || (c<l && l<f) || (i<c && c<l) || (i<f && f<l);
    if(intersect_x && intersect_y && intersect_z) cout << "Yes" << endl;
    else cout << "No" << endl;
}
