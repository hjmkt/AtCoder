#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> sw(N, 0);
    int total = 0;
    for(int i=0; i<N; ++i){
        int w;
        cin >> w;
        total += w;
        sw[i] = total;
    }
    int m = INT_MAX;
    for(int i=0; i<N-1; ++i){
        int d = abs(2*sw[i] - total);
        m = min(m, d);
    }
    cout << m << endl;
}
