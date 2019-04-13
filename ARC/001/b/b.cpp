#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int d = abs(a-b);
    int n = d / 10;
    d %= 10;
    int lut[10] = {0, 1, 2, 3, 2, 1, 2, 3, 3, 2};
    n += lut[d];
    cout << n << endl;
}
