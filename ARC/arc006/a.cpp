#include <bits/stdc++.h>

using namespace std;

int main(){
    int c[10] = {};
    int l[10] = {};
    int b = 0;

    int t = 0;
    for(int i=0; i<6; ++i){
        cin >> t;
        ++c[t];
    }
    cin >> b;
    for(int i=0; i<6; ++i){
        cin >> t;
        ++l[t];
    }

    int count = 0;
    for(int i=0; i<10; ++i){
        count += min(c[i], l[i]);
    }
    if(count==6) cout << 1 << endl;
    else if(count==5){
        if(c[b]!=l[b]) cout << 2 << endl;
        else cout << 3 << endl;
    }
    else if(count==4) cout << 4 << endl;
    else if(count==3) cout << 5 << endl;
    else cout << 0 << endl;
}
