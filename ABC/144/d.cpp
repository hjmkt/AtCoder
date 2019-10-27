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
    double a, b, x;
    cin >> a >> b >> x;

    double bd = a*a*b/2;
    if(x<bd){
        double t = a*b*b/(2*x);
        double p = atan(t);
        cout << (p/acos(-1)*180) << endl;
    }
    else{
        double t = 2*b/a-2*x/(a*a*a);
        double p = atan(t);
        cout << setprecision(20) << (p/acos(-1)*180) << endl;
    }
}
