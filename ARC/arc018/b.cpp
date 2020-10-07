#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> x(N);
    vector<long long> y(N);
    for(int i=0; i<N; ++i){
        cin >> x[i] >> y[i];
    }
    long long count = 0;
    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            for(int k=j+1; k<N; ++k){
                long long dx0 = x[i] - x[j];
                long long dy0 = y[i] - y[j];
                long long dx1 = x[i] - x[k];
                long long dy1 = y[i] - y[k];
                long long r = abs(dx0*dy1-dx1*dy0);
                if(r>0 && r%2==0) ++count;
            }
        }
    }
    cout << count << endl;
}
