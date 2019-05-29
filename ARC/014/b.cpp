#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> ws(N);
    for(int i=0; i<N; ++i){
        cin >> ws[i];
    }
    unordered_set<string> uws;
    string last = ws[0];
    uws.insert(last);
    for(int i=1; i<N; ++i){
        if(ws[i][0]!=last[last.length()-1] || uws.count(ws[i])>0){
            if(i%2==0) cout << "LOSE" << endl;
            else cout << "WIN" << endl;
            return 0;
        }
        last = ws[i];
        uws.insert(last);
    }
    cout << "DRAW" << endl;
}
