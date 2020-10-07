#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &s, char delim){
    vector<string> elems;
    stringstream ss(s);
    string buf;
    while(getline(ss, buf, delim)){
        if(!buf.empty()) elems.push_back(buf);
    }
    return elems;
}

int main(){
    string buf;
    cin >> buf;
    auto xy = split(buf, '/');
    __int128_t x = stoll(xy[0]), y = stoll(xy[1]);
    bool found = false;
    for(__int128_t n=2*x/y; n<=2*x/y+1; ++n){
        __int128_t m = n*(n+1)/2-x*n/y;
        __int128_t numer = n*(n+1) - 2*m;
        __int128_t denom = 2 * n;
        if(x*denom==y*numer && n>0 && m<=n){
            found = true;
            cout << (long long)n << " " << (long long)m << endl;
        }
    }
    if(!found) cout << "Impossible" << endl;
}
