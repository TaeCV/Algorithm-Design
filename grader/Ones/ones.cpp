#include <bits/stdc++.h>

using namespace std;

int ones(int n, vector<int> &Q, int k) {
    if (n <= 11)
        return min(n, 13 - n);
    int qt = n / Q[k];
    int r = n % Q[k];
    return qt * (k) + min(ones(r, Q, k - 1), k + ones(Q[k] - r, Q, k - 1));
}

int main() {
    int n, k = 0;
    cin >> n;
    vector<int> Q(10);
    while (Q[k] <= n) {
        Q[k + 1] = Q[k] * 10 + 1, ++k;
    }
    cout << ones(n, Q, k);
}