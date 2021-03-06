#include <iostream>
using namespace std;

int ans(int n, int m, int k) {
    if (n > k) {
        return (m + ans(n - 1, m, k)) % n;
    } else {
        return 0;
    }
}

int main() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        // int ans = 0;
        // for (int i = 1; i <= n; i++) ans = (ans + m) % i;
        // cout << ans + 1 << endl;
        cout << ans(n, m, n - k) + 1 << endl;
    }
    return 0;
}

