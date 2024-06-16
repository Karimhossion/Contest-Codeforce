#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b; 
        
        ll max_profit = 0;
        

        ll limit = min(n, b);
        for (ll k = 0; k <= limit; ++k) {
            ll sum_promotional = k * b - k * (k - 1) / 2;
            ll remaining_buns = n - k;
            ll profit = sum_promotional + remaining_buns * a;
            max_profit = max(max_profit, profit);
        }
        
        cout << max_profit << endl;
    }

    return 0;
}
