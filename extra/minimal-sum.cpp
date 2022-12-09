#include <iostream>
#include <vector>
using namespace std;

int main() {
    int len, lesser, begin, end;
    cin >> len;

    vector<int> nums(len), dp(len);

    for (int i = 0; i < len; i++)
        cin >> nums[i];

    dp[0] = nums[0];
    lesser = dp[0];
    end = 0;
    for (int i = 1; i < len; i++) {
        dp[i] = nums[i] + min(0, dp[i - 1]);
        if (lesser > dp[i]) {
            lesser = dp[i];
            end = i;
        }
    }

    for (begin = end - 1; begin >= 0; begin--) {
        if (dp[begin] > 0) {
            begin++;
            break;
        }
    }

    if (begin < 0) begin++;

    cout << "Elements: ";
    for (begin; begin <= end; begin++) {
        cout << nums[begin];
        cout << ((begin == end) ? '\n' : ' ');
    }

    cout << "MINIMAL SUM = " << lesser << '\n';
    return 0;
}