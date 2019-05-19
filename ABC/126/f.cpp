#include <bits/stdc++.h>

using namespace std;

int main(){
    int M, K;
    cin >> M >> K;
    if(K>=1<<M) cout << -1 << endl;
    else if(K==0){
        for(int i=0; i<(1<<M)-1; ++i){
            cout << i << " " << i << " ";
        }
        cout << (1<<M)-1 << " " << (1<<M)-1 << endl;
    }
    else if(M==1) cout << -1 << endl;
    else{
        for(int i=0; i<(1<<M); ++i){
            if(i!=K) cout << i << " ";
        }
        cout << K << " ";
        for(int i=(1<<M)-1; i>=0; --i){
            if(i!=K) cout << i << " ";
        }
        cout << K << endl;
    }
}
