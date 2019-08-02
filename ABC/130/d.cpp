#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()

int main(){
    ll N, K;
    cin >> N >> K;
    vll a(N);
    rep(i, N){
        cin >> a[i];
    }
    vll s(N);
    ll total = 0;
    rep(i, N){
        total += a[i];
        s[i] = total;
    }
    ll count = 0;
    rep(i, N){
        ll c = s[i];
        if(c<K) continue;
        ++count;
        ll left = 0, right = i-1;
        while(left<right){
            ll mid = (left+right+1) / 2;
            if(c-s[mid]>=K){
                left = mid;
            }
            else{
                right = mid-1;
            }
        }
        if(c-s[left]>=K && i>0){
            count += left+1;
        }
    }
    cout << count << endl;
}
