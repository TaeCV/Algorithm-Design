#include <bits/stdc++.h>

using namespace std;

bool bs(vector<int> &A, int l, int r, int val) {
    while (l <= r) {
        int m = (l + r) >> 1;
        if (val == A[m])
            return true;
        else if (val < A[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return false;
}

bool triple(vector<int> &A, int q, int n) {
    int remain;
    for (int i = 0; i < n - 1; ++i) {
        if (q < A[i])
            return false;
        for (int j = i + 1; j < n; ++j) {
            remain = q - A[i] - A[j];
            if (remain < A[j])
                break;
            if (bs(A, j + 1, n, remain))
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    while (m--) {
        cin >> q;
        cout << (triple(A, q, n - 1) ? "YES" : "NO") << "\n";
    }
}