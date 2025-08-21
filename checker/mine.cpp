#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x : a) cin >> x;

    for(int i=0; i<n; i++){
        cout << a[i] << " \n"[i == n-1];
    }

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}