#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int N;
    string cm;
    cin >> N >> cm;
    vector<string> sc = {
        "AA", "AB", "AX", "AY",
        "BA", "BB", "BX", "BY",
        "XA", "XB", "XX", "XY",
        "YA", "YB", "YX", "YY",
    };
    int shortest = INT_MAX;
    for(int i=0; i<sc.size()-1; ++i){
        for(int j=i+1; j<sc.size(); ++j){
            int l = 0;
            for(int k=0; k<cm.size(); ++k){
                if(k<cm.size()-1){
                    string t = cm.substr(k, 2);
                    if(t==sc[i] || t==sc[j]) ++k;
                }
                ++l;
            }
            if(l<shortest) shortest = l;
        }
    }
    cout << shortest << endl;
}
