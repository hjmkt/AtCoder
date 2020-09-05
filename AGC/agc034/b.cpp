#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> a;
    int idx = 0;
    long long total = 0;
    for(int i=0; i<s.length(); ++i){
        if(s[i]=='A') ++idx;
        else if(i+1<s.length() && s[i]=='B' && s[i+1]=='C'){
            a.push_back(idx);
            idx = 0;
            ++i;
        }
        else{
            for(int j=0; j<a.size(); ++j){
                total += a[j]*((long long)a.size()-j);
            }
            idx = 0;
            a.resize(0);
        }
    }
    for(int j=0; j<a.size(); ++j){
        total += a[j]*((long long)a.size()-j);
    }
    cout << total << endl;
}
