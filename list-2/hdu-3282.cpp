//UVA: Running Median

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int nTests, nCase, size, aux, count;

    cin >> nTests;

    while (nTests--) {
        cin >> nCase >> size;
        cout << nCase << ' ' << (size - 1) / 2 + 1 << '\n';

        vector<int> nums;

        count = 0;
        for (int i = 1; i <= size; i++) {
            cin >> aux;
            nums.push_back(aux);

            if (i % 2) {
                sort(nums.begin(), nums.end());
                count++;
                aux = ((i + 1) / 2) - 1;

                (count % 10 == 0 || i == size) ? cout << nums[aux] << '\n' : cout << nums[aux] << ' ';
            }
        }
    }
    return 0;
}
