#include <iostream>

using namespace std;

int main(){
    int y;
    cin >> y;

    bool res = false;
    if(y%4==0) res = true;
    if(y%100==0) res = false;
    if(y%400==0) res = true;

    cout << (res? "YES" : "NO") << endl;
}
