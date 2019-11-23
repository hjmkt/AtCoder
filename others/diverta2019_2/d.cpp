#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define REP(i, x, n) for(ll i=x; i<(ll)n; ++i)
#define rep(i, x) REP(i, 0, x)
#define all(v) v.begin(), v.end()

int main(){
    ll N;
    cin >> N;
    ll gA, sA, bA;
    cin >> gA >> sA >> bA;
    ll gB, sB, bB;
    cin >> gB >> sB >> bB;

    ll mAB = 0;
    ll mBA = 0;
    for(ll g=0; g<=N/gA; ++g){
        for(ll s=0; s<=(N-g*gA)/sA; ++s){
            ll total = gB*g + sB*s;
            ll left = (N-g*gA) - s*sA;
            if(bA<bB){
                total += left/bA * bB + left%bA;
            }
            else{
                total += left;
            }
            if(total>mAB) mAB = total;
        }
    }
    for(ll g=0; g<=N/gB; ++g){
        for(ll s=0; s<=(N-g*gB)/sB; ++s){
            ll total = gA*g + sA*s;
            ll left = (N-g*gB) - s*sB;
            if(bB<bA){
                total += left/bB * bA + left%bB;
            }
            else{
                total += left;
            }
            if(total>mBA) mBA = total;
        }
    }
    cout << max(mAB, mBA) << endl;
}
