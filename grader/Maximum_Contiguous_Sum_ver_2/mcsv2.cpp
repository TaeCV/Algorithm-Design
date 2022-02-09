#include <bits/stdc++.h>

using namespace std;

int mcs(vector<int> &A, int start, int end) {
    if (start == end)
        return A[start] - A[start - 1];
    int mid = (start + end) >> 1;
    int a = mcs(A, start, mid);
    int b = mcs(A, mid + 1, end);
    int minLeft = A[mid] - A[start - 1];
    for (int i = start; i < mid; ++i) {
        minLeft = min(A[mid] - A[i], minLeft);
    }
    int minRight = A[mid + 1] - A[mid];
    for (int i = mid + 2; i <= end; ++i) {
        minRight = min(A[i] - A[mid], minRight);
    }
    int c = minLeft + minRight;
    return min(a, min(b, c));
}

int main() {
    int n, mx;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        if (i == 1)
            mx = A[i];
        else if (mx < A[i])
            mx = A[i];
        A[i] += A[i - 1];
    }
    int minSum = mcs(A, 1, n);
    cout << (minSum == A[n] ? mx : max(A[n] - minSum, A[n]));
}