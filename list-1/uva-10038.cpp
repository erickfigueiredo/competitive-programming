#include <iostream>
using namespace std;

int main() {
    int n, aux;
    bool jolly;

    while(cin >> n) {
        int nums[n]={0}, cont[n]={0};

        jolly = true;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            
            if(i) {
                aux = abs(nums[i]-nums[i-1]);
                if(aux < n && !cont[aux]) cont[aux]++;
            }
        }

        for(int i = 1; i < n; i++)
            if(!cont[i]){
                jolly=false;
                break;
            }
        
        jolly ? cout << "Jolly\n" : cout << "Not jolly\n";
    }
    return 0;
}