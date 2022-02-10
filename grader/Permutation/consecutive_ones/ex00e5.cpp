#include <bits/stdc++.h>

using namespace std;

void consecutive_ones(int &n, int &k, int len, int count, vector<bool> &result, bool status) {
    if (len < n) {
        result[len] = false;
        consecutive_ones(n, k, len + 1, 0, result, status);
        result[len] = true;
        consecutive_ones(n, k, len + 1, count + 1, result, status || count + 1 >= k);
    } else {
        if (status) {
            for (int i = 0; i < n; ++i)
                cout << result[i];
            cout << "\n";
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> result(n);
    consecutive_ones(n, k, 0, 0, result, false);
}