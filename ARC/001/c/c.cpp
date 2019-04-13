#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    char a[8][8] = {};
    for(int y=0; y<8; y++){
        for(int x=0; x<8; x++){
            cin >> a[y][x];
        }
    }
    vector<int> q = {0, 1, 2, 3, 4, 5, 6, 7};
    do{
        bool valid = true;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(a[i][j]=='Q' && q[i]!=j) valid = false;
                if(i!=j && abs(i-j)==abs(q[i]-q[j])) valid = false;
            }
        }
        if(valid){
            for(int y=0; y<8; y++){
                for(int x=0; x<8; x++){
                    cout << (q[y]==x? 'Q' : '.');
                }
                cout << endl;
            }
            return 0;
        }
    }
    while(next_permutation(q.begin(), q.end()));

    cout << "No Answer" << endl;
}
