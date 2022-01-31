#include <bits/stdc++.h>

using namespace std;

int inversion(vector<int> &A, vector<int> &tmp, int start, int stop) {
    if (start < stop) {
        int m = (start + stop) >> 1;
        int b = start;
        int c = m + 1;
        int ans = inversion(A, tmp, start, m) + inversion(A, tmp, m + 1, stop);
        for (int i = start; i <= stop; ++i) {
            if (b > m) {
                tmp[i] = A[c++];
                continue;
            }
            if (c > stop) {
                tmp[i] = A[b++];
                continue;
            }
            if (A[b] > A[c]) {
                ans += (m - b) + 1;
                tmp[i] = A[c++];
            } else {
                tmp[i] = A[b++];
            }
        }
        for (int i = start; i <= stop; ++i)
            A[i] = tmp[i];
        return ans;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), tmp(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cout << inversion(A, tmp, 0, n - 1);
}

// int main() {
//     int n, cnt = 0;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//         for (int j = 0; j < i; ++j) {
//             if (a[j] > a[i]) {
//                 cnt++;
//             }
//         }
//     }
//     cout << cnt;
// }