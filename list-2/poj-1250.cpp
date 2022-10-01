#include <set>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int nTanning, nWA;
    string customers;

    while (true) {
        cin >> nTanning;
        if (!nTanning) break;

        nWA = 0;
        cin >> customers;

        set<char> tanes;

        for(string::iterator c = customers.begin(); c != customers.end(); c++){
            set<char>::iterator it = tanes.find(*c);
            if(it == tanes.end()){
                if(tanes.size() < nTanning) tanes.insert(*c);
                else nWA++;
            } else {
                tanes.erase(*c);
            }
        }

        !nWA ? cout << "All customers tanned successfully.\n" : cout << nWA/2 << " customer(s) walked away.\n";
    }
    return 0;
}
