#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    ll A, B;
    cin >> A >> B;
    ll da = abs(A);
    ll db = abs(B);
    if(da<db) cout << "Ant" << endl;
    else if(da>db) cout << "Bug" << endl;
    else cout << "Draw" << endl;
}
