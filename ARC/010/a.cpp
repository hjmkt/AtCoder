#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    int rem = N;
    vector<int> c(M);
    for(int i=0; i<M; ++i){
        cin >> c[i];
    }
    for(int i=0; i<M; ++i){
        if(rem<=A) rem += B;
        if(rem<c[i]){
            cout << (i+1) << endl;
            return 0;
        }
        rem -= c[i];
    }
    cout << "complete" << endl;
}
