#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> ns;
    for(int i=0; i<N; ++i){
        string s;
        cin >> s;
        stringstream ss;
        for(int j=0; j<s.length(); ++j){
            if(s[j]>='A' && s[j]<='Z') s[j] += 'a'-'A';
            if(s[j]=='z' || s[j]=='r') ss << 0;
            else if(s[j]=='b' || s[j]=='c') ss << 1;
            else if(s[j]=='d' || s[j]=='w') ss << 2;
            else if(s[j]=='t' || s[j]=='j') ss << 3;
            else if(s[j]=='f' || s[j]=='q') ss << 4;
            else if(s[j]=='l' || s[j]=='v') ss << 5;
            else if(s[j]=='s' || s[j]=='x') ss << 6;
            else if(s[j]=='p' || s[j]=='m') ss << 7;
            else if(s[j]=='h' || s[j]=='k') ss << 8;
            else if(s[j]=='n' || s[j]=='g') ss << 9;
        }
        string w = ss.str();
        if(w.length()>0) ns.push_back(w);
    }
    for(int i=0; i<(int)ns.size()-1; ++i){
        cout << ns[i] << " ";
    }
    if(ns.size()>0) cout << ns[ns.size()-1] << endl;
    else cout << endl;
}
