#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    int c[6] = {};
    for(int i=0; i<N; ++i){
        double MT, mT;
        cin >> MT >> mT;
        if(MT>=35) ++c[0];
        else if(MT>=30) ++c[1];
        else if(MT>=25) ++c[2];
        if(mT>=25) ++c[3];
        if(mT<0 && MT>=0) ++c[4];
        if(MT<0) ++c[5];
    }
    cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << " " << c[4] << " " << c[5] << endl;
}
