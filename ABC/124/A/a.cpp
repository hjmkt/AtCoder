#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int total = 0;
    int m = max(a, b);
    if(a==b) cout << m+m << endl;
    else cout << m+m-1 << endl;
}
