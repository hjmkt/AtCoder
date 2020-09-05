#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<long long> c(N+1, -1);
    c[N] = 1;
    vector<int> b(N+1, 0);
    for(int i=0; i<M; ++i){
        int t;
        cin >> t;
        b[t] = 1;
    }

    function<long long(int n)> f = [&](int n){
        if(c[n]>=0) return c[n];
        long long count = 0;
        if(n+1<=N && b[n+1]==0) count += f(n+1);
        if(n+2<=N && b[n+2]==0) count += f(n+2);
        c[n] = count % 1000000007;
        return c[n];
    };
    cout << f(0) << endl;;
}
