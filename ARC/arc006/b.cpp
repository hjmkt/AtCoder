#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, L;
    cin >> N >> L;
    string l[L+1];
    for(int i=0; i<L+1; ++i){
        if(i==0) getline(cin, l[i]);
        getline(cin, l[i]);
        l[i] = " " + l[i] + " ";
    }
    int x = 0, y = L-1;
    while(l[L][x]!='o') ++x;
    while(y>=0){
        if(l[y][x-1]=='-') x -= 2;
        else if(l[y][x+1]=='-') x += 2;
        --y;
    }
    cout << (x/2+1) << endl;
}
