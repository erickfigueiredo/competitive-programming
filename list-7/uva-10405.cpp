#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs(vector<vector<int>>& m, const string& f, const string& s, int fl, int sl) {
    if (m[fl][sl] != -1) return m[fl][sl];

    else {
        if (!fl || !sl) m[fl][sl] = 0;
        else if (f[fl-1] == s[sl-1]) m[fl][sl] = 1 + lcs(m, f, s, fl - 1, sl - 1);
        else m[fl][sl] = max(lcs(m, f, s, fl - 1, sl), lcs(m, f, s, fl, sl - 1));

        return m[fl][sl];
    }
}

int main() {
    string f, s;

    while (getline(cin, f)) {
        getline(cin, s);
        vector<vector<int>> matrix(f.length() + 1, vector<int>(s.length() + 1, -1));
        cout << lcs(matrix, f, s, f.length(), s.length()) << '\n';
    }
    return 0;
}
