#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    double p = 0;
    for(int i=1; i<=N; ++i){
        int count = 0;
        int current = i;
        while(current<K){
            current *= 2;
            ++count;
        }
        p += pow(0.5, count) / N;
    }
    cout << setprecision(12) << p << endl;
}
