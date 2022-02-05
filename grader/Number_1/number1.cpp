#include <bits/stdc++.h>

using namespace std;

int cal(int n, int a, int l, int r) {
    int newA = a >> 1;
    return n <= 1 ? n : ((l <= newA && newA <= r) ? n % 2 : 0) + ((l < newA) ? cal(n / 2, newA, l, min(r, newA - 1)) : 0) + ((newA < r) ? cal(n / 2, newA, max(l - newA, 0), r - newA) : 0);
}

int main() {
    int n, l, r, a = 1;
    cin >> n >> l >> r;
    while (a < n) {
        a <<= 1;
    }
    cout << cal(n, a, l, r);
}