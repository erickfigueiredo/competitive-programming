#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, size, a, b, half, aux;
    cin >> n;

    while (n--) {
        cin >> size >> a >> b;
        half = size / 2;
        int numCheck[size + 1] = { false };
        vector<int> nums;

        numCheck[a] = true;
        numCheck[b] = true;

        aux = 1;
        nums.push_back(a);
        for (int i = size; aux < half; i--)
            if (!numCheck[i] and i > a) {
                nums.push_back(i);

                numCheck[i] = true;
                aux++;
            }

        nums.push_back(b);
        for (int i = 1; i < size + 1; i++)
            if (!numCheck[i] and i < b) {
                nums.push_back(i);

                numCheck[i] = true;
            }

        if (size == nums.size()) {
            for (int i = 0; i < size; i++) {
                i == size - 1 ? cout << nums[i] << '\n' : cout << nums[i] << ' ';
            }
        }
        else cout << "-1\n";

    }
    return 0;
}
