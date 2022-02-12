#include <bits/stdc++.h>

using namespace std;

int fibo(int &n, int len, int a, int b) {
    if (n <= 1)
        return n;
    if (len == n)
        return a + b;
    return fibo(n, len + 1, b, a + b);
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n, 2, 0, 1);
}