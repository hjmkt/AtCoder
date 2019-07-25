#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;

    if(C<D){
        bool r = false;
        for(int i=B; i<=D; ++i){
            if(S[i-1]=='#'){
                if(r){
                    cout << "No" << endl;
                    return 0;
                }
                r = true;
            }
            else r = false;
        }
        r = false;
        for(int i=A; i<C; ++i){
            if(S[i-1]=='#'){
                if(r){
                    cout << "No" << endl;
                    return 0;
                }
                r = true;
            }
            else r = false;
        }
        cout << "Yes" << endl;
    }
    else{
        bool r = false;
        bool w = false;
        for(int i=B; i<=D; ++i){
            if(S[i-2]!='#' && S[i-1]!='#' && S[i]!='#') w = true;
            if(S[i-1]=='#'){
                if(r){
                    cout << "No" << endl;
                    return 0;
                }
                r = true;
            }
            else r = false;
        }
        if(!w){
            cout << "No" << endl;
        }
        else{
            r = false;
            for(int i=A; i<C; ++i){
                if(S[i-1]=='#'){
                    if(r){
                        cout << "No" << endl;
                        return 0;
                    }
                    r = true;
                }
                else r = false;
            }
            cout << "Yes" << endl;
        }
    }
}
