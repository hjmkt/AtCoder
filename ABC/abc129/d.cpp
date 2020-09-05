#include <bits/stdc++.h>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i=0; i<H; ++i){
        cin >> S[i];
    }
    vector<vector<int>> cx(H, vector<int>(W, 0));
    vector<vector<int>> cy(H, vector<int>(W, 0));
    for(int y=0; y<H; ++y){
        int count = 0;
        for(int x=0; x<W; ++x){
            if(S[y][x]=='.') ++count;
            if(S[y][x]=='#'){
                for(int xx=x-1; xx>=0; --xx){
                    if(S[y][xx]=='#') break;
                    cx[y][xx] = count;
                }
                count = 0;
            }
            else if(x==W-1){
                for(int xx=x; xx>=0; --xx){
                    if(S[y][xx]=='#') break;
                    cx[y][xx] = count;
                }
            }
        }
    }

    for(int x=0; x<W; ++x){
        int count = 0;
        for(int y=0; y<H; ++y){
            if(S[y][x]=='.') ++count;
            if(S[y][x]=='#'){
                for(int yy=y-1; yy>=0; --yy){
                    if(S[yy][x]=='#') break;
                    cy[yy][x] = count;
                }
                count = 0;
            }
            else if(y==H-1){
                for(int yy=y; yy>=0; --yy){
                    if(S[yy][x]=='#') break;
                    cy[yy][x] = count;
                }
            }
        }
    }

    int M = 0;
    for(int y=0; y<H; ++y){
        for(int x=0; x<W; ++x){
            int count = cx[y][x] + cy[y][x] - 1;
            M = max(count, M);
        }
    }

    cout << M << endl;
}
