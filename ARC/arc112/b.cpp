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
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll B, C;
    cin >> B >> C;

    if(B>=0){
        ll l_pos = B-C/2;
        ll r_pos = B+max(0ll, C-2)/2;
        ll l_neg = B==0? -(C/2) : C>=1? -B-max(0ll, C-1)/2 : 0;
        ll r_neg = l_neg;
        if(B>0 && C>0) r_neg = -(max(0ll, B-(C-1)/2));
        if(r_neg>=l_pos) cout << (r_pos-l_neg+1) << endl;
        else cout << (r_pos-l_pos+1) + (r_neg-l_neg+1) << endl;
    }
    else{
        ll l_neg = B - C/2;
        ll r_neg = B + max(0ll, C-2)/2;
        ll l_pos = C>=1? -B-(C-1)/2 : r_neg;
        ll r_pos = C>=1? (-B+(C-1)/2) : r_neg;
        if(r_neg>=l_pos) cout << (r_pos-l_neg+1) << endl;
        else cout << (r_pos-l_pos+1) + (r_neg-l_neg+1) << endl;
    }
}
