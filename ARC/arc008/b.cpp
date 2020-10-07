#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    string name, kit;
    cin >> name >> kit;
    int name_count[26] = {};
    int kit_count[26] = {};
    for(int i=0; i<name.length(); ++i){
        ++name_count[name[i]-'A'];
    }
    for(int i=0; i<kit.length(); ++i){
        ++kit_count[kit[i]-'A'];
    }
    int count = 0;
    for(int i=0; i<26; ++i){
        if(name_count[i]>0){
            if(kit_count[i]==0){
                cout << -1 << endl;
                return 0;
            }
            else{
                count = max(count, (name_count[i]+kit_count[i]-1)/kit_count[i]);
            }
        }
    }
    cout << count << endl;
}
