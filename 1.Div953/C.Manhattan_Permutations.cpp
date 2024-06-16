#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> permutation;

    // Initialize sum and the array permutation with numbers from 1 to n
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += abs(i - (n - i + 1));  // Calculate initial sum of absolute differences
        permutation.push_back(i);
    }

    // If k is odd or sum is less than k, output "NO"
    if (k % 2 == 1 || sum < k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int ind = 0;
        int N = n;

        // Adjust the permutation to try to reach the sum k
        while (k > (N - 1) * 2) {
            swap(permutation[ind], permutation[n - ind - 1]);  // Swap the elements
            k -= (N - 1) * 2;  // Decrease k accordingly
            N -= 2;
            ind++;
        }

        k /= 2;
        swap(permutation[ind], permutation[ind + k]);  // Perform the final swap to achieve exact k

        // Print the resulting permutation
        for (auto i = 0; i < permutation.size(); i++) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
