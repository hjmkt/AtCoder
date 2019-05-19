#include <bits/stdc++.h>

using namespace std;

int main(){
    string S;
    cin >> S;
    string first = S.substr(0, 2);
    string second = S.substr(2, 2);
    int f = stoi(first);
    int s = stoi(second);
    if(f<=12 && f>=1){
        if(s<=12 && s>=1) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }
    else if(s<=12 && s>=1){
        cout << "YYMM" << endl;
    }
    else cout << "NA" << endl;
}
