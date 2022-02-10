#include <bits/stdc++.h>

using namespace std;
int mL[200005], mR[200005];

int mcs(vector<int> &A, int start, int end, int w) {
    if (start == end) {
        return A[start] - A[start - 1];
    }
    int mid = (start + end) >> 1;
    int ans = max(mcs(A, start, mid, w), mcs(A, mid + 1, end, w));
    int left = A[mid] - A[mid - 1];
    for (int i = mid - 1; i >= start; --i) {
        mL[i] = left = max(left, A[mid] - A[i]);
    }
    int right = A[mid + 1] - A[mid];
    for (int i = mid + 1; i <= end; ++i) {
        mR[i] = right = max(right, A[i] - A[mid]);
    }
    if (w > end - start) {
        return max(ans, left + right);
    }
    for (int i = 1; i <= w - 1; ++i) {
        ans = max(ans, mL[mid - i] + mR[mid + (w - i)]);
    }
    return ans;
}

int main() {
    int n, w, mx;
    cin >> n >> w;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        if (i == 1)
            mx = A[i];
        if (mx < A[i])
            mx = A[i];
        A[i] += A[i - 1];
    }
    cout << (w == 1 ? mx : mcs(A, 1, n, w));
}