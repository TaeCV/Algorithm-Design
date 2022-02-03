#include <bits/stdc++.h>

using namespace std;

int mod_expo(int x, int n, int k) {
    if (n == 1)
        return x % k;
    int tmp = mod_expo(x, n / 2, k);
    if (n % 2 == 0) {
        return (tmp * tmp) % k;
    } else {
        tmp = (tmp * tmp) % k;
        return (tmp * x % k) % k;
    }
}

int main() {
    int x, n, k;
    cin >> x >> n >> k;
    cout << mod_expo(x, n, k);
}