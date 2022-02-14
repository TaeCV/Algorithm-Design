#include <bits/stdc++.h>

using namespace std;

int n, A[10005], a, b, tmp;

int dp() {
    if (n == 1)
        return A[1];
    if (n == 2)
        return max(A[1], A[2]);
    a = A[1];
    b = max(A[1], A[2]);
    for (int i = 3; i <= n; ++i) {
        tmp = max(b, a + A[i]);
        a = b;
        b = tmp;
    }
    return b;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    cout << dp();
}