#include <bits/stdc++.h>

using namespace std;

void msc(vector<int> &A, int s, int e, int &mx) {
    if (s == e) {
        mx = A[s];
        return;
    }
    msc(A, s, e - 1, mx);
    if (mx < A[e]) {
        mx = A[e];
    }
    for (int i = s; i < e; ++i) {
        int tmp = A[e] - A[i];
        if (mx < tmp) {
            mx = tmp;
        }
    }
}

int main() {
    int n, mx = 0;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (i > 0)
            A[i] += A[i - 1];
    }
    msc(A, 0, n - 1, mx);
    cout << mx;
}