#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> ws(1, INT_MAX);
    for(int i=0; i<N; ++i){
        int w;
        cin >> w;
        sort(ws.begin(), ws.end());
        bool found = false;
        for(int j=0; j<ws.size(); ++j){
            if(ws[j]>=w){
                ws[j] = w;
                found = true;
                break;
            }
        }
        if(!found) ws.push_back(w);
    }
    cout << ws.size() << endl;
}
