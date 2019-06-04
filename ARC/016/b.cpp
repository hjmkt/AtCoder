#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> p(9, 0);
    int count = 0;
    for(int i=0; i<N; ++i){
        string s;
        cin >> s;
        for(int j=0; j<9; ++j){
            if(s[j]=='x'){
                ++count;
                p[j] = 0;
            }
            else if(s[j]=='o'){
                if(p[j]==0) ++count;
                p[j] = 1;
            }
            else p[j] = 0;
        }
    }
    cout << count << endl;
}
