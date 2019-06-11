#include <bits/stdc++.h>

using namespace std;

int main(){
    double height, bmi;
    cin >> height >> bmi;
    height /= 100;
    double weight = bmi*height*height;
    cout << setprecision(10) << weight << endl;
}
