#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    int n, k, min, dist;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cin >> k;

    list<int>numsCopy(nums.begin(), nums.end());
    
    auto maxEl = numsCopy.begin();
    for(auto it = numsCopy.begin(); it != numsCopy.end(); it++)
        if(*it > *maxEl) {
            
            maxEl = it;
        }a.e

    dist = k - distance(numsCopy.begin(), maxEl);
    
    if(dist > 0) {
        for(int i = 0; i <  dist; i++){
            auto minEl = maxEl;
            for(auto it = maxEl; it != numsCopy.end(); it++) {
                if(*minEl > *it) {
                    minEl = it;
                }
            }

            numsCopy.erase(minEl);
        }
    }

    nums = vector<int>(maxEl, numsCopy.end());

    for(auto i: nums) cout << i;

    cout << '\n';
}
