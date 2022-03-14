#include <bits/stdc++.h>

using namespace std;

void display(int len, int n, int m, int A[], int left) {
    if (left < (n - len))
        return;
    if (len < n) {
        for (int i = 1; i <= (m - n + 1); ++i) {
            A[len] = i;
            display(len + 1, n, m, A, left - i);
        }
    } else if (len == n && left == 0) {
        for (int i = 0; i < n; ++i)
            cout << A[i] << " ";
        cout << "\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int A[n];
    display(0, n, m, A, m);
}