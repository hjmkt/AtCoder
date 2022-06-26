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

    ll A, B, C;
    cin >> A >> B >> C;
    if(A<B) swap(A, B);
    if(A<C) swap(A, C);
    if(B<C) swap(B, C);
    if(A==B&&B==C) cout << A << endl;
    else{
        if(A==B) cout << A << endl;
        else{
            if(A>B+C) cout << -1 << endl;
            else if(A==B+C) cout << A << endl;
            else{
                ll d = B-C;
                A -= d;
                B -= d;
                // A>=B=C
                if(A==B+C) cout << d+A << endl;
                else{
                    // A>B=C
                    ll r = (A - B) / 2;
                    d += 2 * r;
                    A -= 2*r;
                    B -= r;
                    C -= r;
                    // A==1?+B=C
                    if(A==B) cout << d+A << endl;
                    else if(B>0){
                        d += 2;
                        A -= 2;
                        --B;
                        --C;
                        cout << d+A << endl;
                    }
                    else cout << -1 << endl;
                }
            }
        }
    }
}
