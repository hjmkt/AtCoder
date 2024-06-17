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

    string S, T;
    cin >> S >> T;

    ll first = S.find_first_of(T[0]+'a'-'A');
    if(first==string::npos){
        cout << "No" << endl;
        return 0;
    }
    ll second = S.find_first_of(T[1]+'a'-'A', first+1);
    if(second==string::npos){
        cout << "No" << endl;
        return 0;
    }
    ll third = S.find_first_of(T[2]+'a'-'A', second+1);
    if(third==string::npos){
        if(T[2]=='X') cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}
