#include <iostream>
#include <list>
using namespace std;

int main() {
    int n, m, aux, count;

    while (1){
        count = 0;
        cin >> n >> m;

        if (!n && !m) break;

        list<int> lN, lM;

        for (int i = 0; i < n; i++){
            cin >> aux;
            lN.push_back(aux);
        }

        for (int i = 0; i < n; i++){
            cin >> aux;
            lM.push_back(aux);
        }

        list<int>::iterator itN = lN.begin(), itM = lM.begin(); 
        while(itN != lN.end() && itM != lM.end()){
            if(*itN == *itM){
                count++;
                itN++;
                itM++;
            } else if (*itN < *itM) itN++;
            else itM++;
        }
        cout << count << endl;
    }

    return 0;
}