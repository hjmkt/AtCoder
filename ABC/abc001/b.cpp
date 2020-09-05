#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m;
    cin >> m;

    if(m<100) cout << "00" << endl;
    else if(m<=5000) cout << (m<1000? ("0"+to_string(m*10/1000)) : to_string(m*10/1000)) << endl;
    else if(m<=30000) cout << (m/1000+50) << endl;
    else if(m<=70000) cout << ((m/1000-30)/5+80) << endl;
    else cout << 89 << endl;
}

