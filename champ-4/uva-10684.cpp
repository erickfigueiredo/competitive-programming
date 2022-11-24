#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    int v[n];
    int aux;
    for(int i = 0;i<n;i++)
        cin >> v[i];

    int f[n];
    f[0] = v[0]; int m=v[0];

    for(int i = 1;i<n;i++){
        f[i] = max(f[i-1]+v[i],v[i]);
        m = max(f[i],m);
    }

    if(m <= 0){
        cout << "Losing streak.\n";
    }else{
        cout << "The maximum winning streak is " << m << ".\n";
    }


}

int main(){
    int n;
    while(cin >> n){
        if(!n) break;
        solve(n);
    }
}