#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, k, aux, acc;

    while(cin >> h >> k) {
        if(!h && !k) break;

        vector<int> heads, knights;
        for(int i = 0; i < h+k; i++){
            cin >> aux;
            if(i < h) heads.push_back(aux);
            else knights.push_back(aux);
        }

        if(heads.size() > knights.size()) {
            cout << "Loowater is doomed!\n";
            continue;
        }
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());

        auto itH = heads.begin();
        auto itK = knights.begin();

        acc = 0;
        while(itH != heads.end() && itK != knights.end()) {
            if(*itH <= *itK) {
                acc += *itK;
                itH++;
                itK++;
            } else {
                itK++;
            }
        }

        if(itH == heads.end()){
            cout << acc << '\n';
        } else {
            cout << "Loowater is doomed!\n";
        }
    }
    return 0;
}