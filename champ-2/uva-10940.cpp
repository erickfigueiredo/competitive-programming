#include <iostream>
#include <queue>
using namespace std;

void fillArray(vector<int>& r, int limit=5e5) {
    int count = 0;
    for(int i = 1;; i++){
        int p = 1 << i;

        for(int j = 2; j <= p; j+=2){
            count++;
            if(count > limit) goto end;
            r.push_back(j);

        }
    }
    end:
    return;
}

int main() {
    int n;
    vector <int> results = {1};

    fillArray(results);

    while(cin >> n){
        if(!n) break;

        cout << results[n-1] << endl;
    }
    
    return 0;
}

/*
int main()
{
    int qtd;
    while (cin >> qtd)
    {
        if (!qtd)
            break;

        queue<int> q;

        for (int i = 1; i <= qtd; i++)
            q.push(i);

        for (int i = 0; q.size() > 1; i++)
        {
            if (i % 2 == 0)
                q.pop();
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
        cout << q.front() << '\n';
    }

    return 0;
}
*/