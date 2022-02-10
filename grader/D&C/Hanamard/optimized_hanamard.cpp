#include <bits/stdc++.h>

using namespace std;

void hanamard(vector<int> &weight, int x, int size) {
    if (size == 1) {
        return;
    }
    int newSize = size >> 1;
    hanamard(weight, x, newSize);
    hanamard(weight, x + newSize, newSize);
    for (int i = 0; i < newSize; ++i) {
        weight[x + i] += weight[x + i + newSize];
        weight[x + i + newSize] = weight[x + i] - 2 * weight[x + i + newSize];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> weight(n), answer(n);
    for (int i = 0; i < n; ++i)
        cin >> weight[i];
    hanamard(weight, 0, n);
    for (auto &x : weight)
        cout << x << " ";
}