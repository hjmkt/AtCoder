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

    ll N;
    cin >> N;
    ll mn = LLONG_MAX;
    ll smn = LLONG_MAX;
    ll v = -1;
    ll sv = -1;
    REP(i, 3, N+1){
        cout << "? 1 " << i << endl; 
        ll d0, d1;
        cin >> d0;
        cout << "? 2 " << i << endl; 
        cin >> d1;
        ll d = d0 + d1;
        if(d<mn){
            mn = d;;
            v = i;
        }
        else if(d==mn){
            smn = d;
            sv = i;
        }
    }
    if(mn!=3) cout << "! " << mn << endl;
    else{
        if(N==3) cout << "! 1" << endl;
        else if(mn!=smn) cout << "! 1" << endl;
        else{
            cout << "? " << v << " " << sv << endl;
            ll d;
            cin >> d;
            if(d==1) cout << "! " << mn << endl;
            else{
                cout << "! 1" << endl;
            }
        }
    }
}
