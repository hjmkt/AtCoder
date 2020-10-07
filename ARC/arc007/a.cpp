#include <bits/stdc++.h>

using namespace std;

int main(){
    char X;
    string s;
    cin >> X >> s;
    stringstream ss;
    for(int i=0; i<s.length(); ++i){
        if(s[i]!=X) ss << s[i];
    }
    cout << ss.str() << endl;
}
