#include <bits/stdc++.h>

using namespace std;

void merge_count(vector<int> &A, int start, int end, int &k) {
    if (k == 0 || end - start == 1)
        return;
    int mid = (start + end) >> 1;
    k -= 2;
    swap(A[mid - 1], A[mid]);
    merge_count(A, start, mid, k);
    merge_count(A, mid + 1, end, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        A[i] = i + 1;
    if ((k & 1) && ((k >> 1) < n)) {
        merge_count(A, 0, n, --k);
        for (int i = 0; i < n; ++i)
            cout << A[i] << " ";
    } else
        cout << "-1";
}