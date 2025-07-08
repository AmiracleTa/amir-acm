#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#ifdef ONLINE_JUDGE
    #define debug(...) 42;
    #define out(x) 114514;
#else
    #include "_debug.hpp"
#endif

const int inf = 0x3f3f3f3f;

void solve(){
	int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
	
	return 0;
}
