#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()

int main(){
    ll N;
    cin >> N;
    vll a(N);
    rep(i, N){
        cin >> a[i];
    }
    vll t;
    rep(i, N){
        ll l = 0, r = (ll)t.size()-1;
        while(l<r){
            ll mid = (l+r) / 2;
            if(t[mid]>=a[i]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        if(r<(ll)t.size() && r>=0 && t[r]<a[i]){
            t[r] = a[i];
        }
        else{
            t.push_back(a[i]);
        }
    }
    cout << t.size() << endl;
}
