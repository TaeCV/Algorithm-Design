#include <bits/stdc++.h>

using namespace std;

int mcs(vector<int> &A, int s, int e) {
    if (s == e)
        return s == 0 ? A[s] : A[s] - A[s - 1];
    int m = (s + e) >> 1;
    int a = mcs(A, s, m);
    int b = mcs(A, m + 1, e);
    int left = s == 0 ? A[m] : A[m] - A[s - 1];
    for (int i = s; i < m; ++i) {
        left = max(left, A[m] - A[i]);
    }
    int right = A[m + 1] - A[m];
    for (int i = m + 2; i <= e; ++i) {
        right = max(right, A[i] - A[m]);
    }
    int c = left + right;
    return max(max(a, b), c);
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), S(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (i > 0)
            A[i] += A[i - 1];
    }
    cout << mcs(A, 0, n - 1);
}

// int main() {
//     int n, x, sum = 0, ans = -1e9;
//     cin >> n;
//     for (int i = 0; i < n; ++i) {
//         cin >> x;
//         sum += x;
//         ans = max(ans, sum);
//         sum = max(sum, 0);
//     }
//     cout << ans;
// }