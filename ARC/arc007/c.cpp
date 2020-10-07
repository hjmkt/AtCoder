#include <bits/stdc++.h>

using namespace std;

int main(){
    string p;
    cin >> p;
    int n = p.length();
    function<int(string, string, int)> solve = [&](string acc, string p, int offset){
        bool valid = true;
        for(int i=offset; i<acc.length(); ++i){
            if(acc[i]=='x'){
                valid = false;
                break;
            }
        }
        if(valid) return 0;
        if(offset>=p.length()) return 10;
        int n0 = solve(acc, p, offset+1);
        string new_acc(acc);
        for(int i=0; i+offset<acc.length(); ++i){
            if(p[i%p.size()]=='o') new_acc[i+offset] = 'o';
        }
        int n1 = 1+solve(new_acc, p, offset+1);
        return min(n0, n1);
    };
    cout << 1+solve(p+p, p, 1) << endl;
}
