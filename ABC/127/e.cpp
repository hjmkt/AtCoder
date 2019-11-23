#include <bits/stdc++.h>

using namespace std;

int main(){
    long long N, M, K;
    cin >> N >> M >> K;
    vector<long long> c(K+1, 0);
    c[2] = 0;
    for(int i=3; i<=K; ++i){
        c[i] = c[i-1] * (((N-1)*M*(M-1)/2 + (M-1)*N*(N-1)/2 - i)%1000000007) % 1000000007;
    }
    cout << c[K] << endl;
}
