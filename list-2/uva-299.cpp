#include <iostream>
using namespace std;

int main() {
    int tests, n;

    cin >> tests;

    while(tests--) {
        cin >> n;
        int nums[n];

        for(int i = 0; i < n; i++)
            cin >> nums[i];

        int n_invertions = 0;

        for(int i = 0; i < n-1; i++)
            for(int j = i+1; j < n; j++)
                if(nums[i] > nums[j]) 
                    n_invertions++;

        printf("Optimal train swapping takes %d swaps.\n", n_invertions);
    }
    return 0;
}