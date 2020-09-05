#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()

int main(){
    cout << setprecision(20);
    string s;
    cin >> s;

    if(s=="SUN") cout << 7 << endl;
    else if(s=="MON") cout << 6 << endl;
    else if(s=="TUE") cout << 5 << endl;
    else if(s=="WED") cout << 4 << endl;
    else if(s=="THU") cout << 3 << endl;
    else if(s=="FRI") cout << 2 << endl;
    else  cout << 1 << endl;
}
