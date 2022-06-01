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

    ll H, W;
    cin >> H >> W;
    vvll A(H, vll(W, 0)), B(H, vll(W, 0));
    rep(i, H) rep(j, W) cin >> A[i][j];
    rep(i, H) rep(j, W) cin >> B[i][j];

    ll count = 0;
    rep(i, H-1){
        rep(j, W-1){
            if(A[i][j]!=B[i][j]){
                ll d = B[i][j] - A[i][j];
                A[i][j] += d;
                A[i+1][j] += d;
                A[i][j+1] += d;
                A[i+1][j+1] += d;
                count += abs(d);
            }
        }
        if(A[i][W-1]!=B[i][W-1]){
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i, W){
        if(A[H-1][i]!=B[H-1][i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << count << endl;
}
