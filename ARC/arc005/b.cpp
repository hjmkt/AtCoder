#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y;
    string W;
    cin >> x >> y >> W;
    x -= 1;
    y -= 1;
    string c[9];
    for(int i=0; i<9; ++i){
        cin >> c[i];
    }
    int dx = 0, dy = 0;
    if(W=="L") dx = -1;
    else if(W=="R") dx = 1;
    else if(W=="U") dy = -1;
    else if(W=="D") dy = 1;
    else if(W=="LU") dx = dy = -1;
    else if(W=="LD"){
        dx = -1;
        dy = 1;
    }
    else if(W=="RU"){
        dx = 1;
        dy = -1;
    }
    else dx = dy = 1;

    string res = "";
    for(int i=0; i<4; ++i){
        res += c[y][x];
        if(x==0) dx = abs(dx);
        if(x==8) dx = -abs(dx);
        if(y==0) dy = abs(dy);
        if(y==8) dy = -abs(dy);
        x += dx;
        y += dy;
    }
    cout << res << endl;
}
