#include <bits/stdc++.h>

using namespace std;

void hanamard(vector<int> &answer, vector<int> &weight, int x, int y, int size, int mul) {
    if (size == 1) {
        answer[x] += weight[y] * mul;
        return;
    }
    int newSize = size >> 1;
    hanamard(answer, weight, x, y, newSize, mul);
    hanamard(answer, weight, x, y + newSize, newSize, mul);
    hanamard(answer, weight, x + newSize, y, newSize, mul);
    hanamard(answer, weight, x + newSize, y + newSize, newSize, -mul);
}

int main() {
    int n;
    cin >> n;
    vector<int> weight(n), answer(n);
    for (int i = 0; i < n; ++i)
        cin >> weight[i];
    hanamard(answer, weight, 0, 0, n, 1);
    for (auto &x : answer)
        cout << x << " ";
}
