#include <bits/stdc++.h>

using namespace std;

long long n, k, M[10005], S[10];

long long process(int left) {
    if (left <= 0)
        return left == 0;
    if (M[left] > 0)
        return M[left];
    long long sum = 0;
    for (int i = 0; i < k; ++i)
        sum += process(left - S[i]) % 1000003;
    return M[left] = sum % 1000003;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
        cin >> S[i];
    cout << process(n);
}