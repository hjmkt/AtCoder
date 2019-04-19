#include <iostream>

using namespace std;

int main(){
    string colors;
    cin >> colors;
    int count = 0;
    for(int i=0; i<colors.length(); ++i){
        if(colors[i]==i%2+'0') ++count;
    }
    cout << min(count, (int)colors.length()-count) << endl;
}
