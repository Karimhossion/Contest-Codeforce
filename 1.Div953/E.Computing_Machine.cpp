#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 1'000'005;
int n, k;
int a[N], c[N << 1];
int dsu[N << 1];

bool np[1001];
vector<int> prime;
vector<int> gmaj[N];

int getpar(int x) {
    if (dsu[x] < 0) return x;
    dsu[x] = getpar(dsu[x]);
    return dsu[x];
}

bool join(int x, int y) {
    x = getpar(x);
    y = getpar(y);
    if (x == y) return false;
    if (dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
    return true;
}

void solve() {
    cin >> n >> k;

    vector<int> dmaj;
    vector<vector<int>> pmaj(2*n);

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) ans += n - 2 + (i == 0);
    } 

    for (int i = 0; i < n + n - 1; i++) {
        if (i < n - 1) c[i] = a[i + 1];
        else c[i] = a[i - n + 1];
    }
    n = (n << 1) - 1;

    for (int i = 0; i < n; i++) {
        int tmp = c[i];
        for (auto j : prime) {
            if (j * j > c[i]) break;
            if (tmp % j == 0) {
                gmaj[j].push_back(i);
                dmaj.push_back(j);
                pmaj[i].push_back(j);
            }
            while (tmp % j == 0) tmp /= j;
        }
        if (tmp > 1) {
            gmaj[tmp].push_back(i);
            dmaj.push_back(tmp);
            pmaj[i].push_back(tmp);
        }
    }
    sort(dmaj.begin(), dmaj.end());
    dmaj.erase(unique(dmaj.begin(), dmaj.end()), dmaj.end());

    for (auto d : dmaj) {
        reverse(gmaj[d].begin(), gmaj[d].end());
    }

    for (int i = 0; i < n; i++) {
        dsu[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (auto p : pmaj[i]) {
            while (!gmaj[p].empty() && gmaj[p].back() < i - k) gmaj[p].pop_back();
            while (!gmaj[p].empty() && gmaj[p].back() <= i + k) {
                join(gmaj[p].back(), i);
                gmaj[p].pop_back();
            }
        }
    }

    for (auto d : dmaj) {
        while (!gmaj[d].empty()) gmaj[d].pop_back();
    }

    for (int i = 0; i < n; i++) {
        if (getpar(i) == i) {
            ans++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    np[0] = np[1] = true;
    for (int i = 2; i <= 1000; i++) {
        if (np[i]) continue;
        prime.push_back(i);
        for (int j = i * i; j <= 1000; j += i) {
            np[j] = true;
        }
    }

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
 
