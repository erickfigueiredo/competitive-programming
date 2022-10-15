#include <iostream>

using namespace std;

int main(){
    int p0,p1,p2,p3,p4,t0,t1,t2,t3,t4;
    while(cin >> p0 >> p1 >> p2 >> p3 >> p4){
        cin >> t0 >> t1 >> t2 >> t3 >> t4;
        if (p0 != t0 && p1 != t1 && p2 != t2 && p3 != t3 && p4 != t4)
            cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}
