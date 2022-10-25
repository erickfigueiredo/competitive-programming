#include <iostream>
#include <vector>
using namespace std;

int main() {
    int minutes, nTracks, curr, best, cds;

    while (cin >> minutes >> nTracks) {
        vector <int> tracks(nTracks);

        for (int i = 0; i < nTracks; i++)
            cin >> tracks[i];

        best = 0;
        for (int i = 0; i < (1 << nTracks); i++) {
            curr = 0;
            for (int j = 0; j < nTracks; j++) {
                if (curr > minutes) break;
                if ((1 << j) & i)
                    curr += tracks[j];
            }

            if (curr > best && curr <= minutes) {
                best = curr;
                cds = i;
            }
        }

        for (int i = 0; i < 20; i++)
            if ((1 << i) & cds)
                printf("%d ", tracks[i]);

        printf("sum:%d\n", best);
    }

    return 0;
}