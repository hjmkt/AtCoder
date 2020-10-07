#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    map<char, char> d = {{'O', '0'}, {'D', '0'}, {'I', '1'}, {'Z', '2'}, {'S', '5'}, {'B', '8'}};
    for(int i=0; i<s.length(); ++i){
        s[i] = d.count(s[i])>0? d[s[i]] : s[i];
    }
    cout << s << endl;
}
