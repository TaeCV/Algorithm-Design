#include <bits/stdc++.h>

using namespace std;

void recur(vector<vector<int>> &H, int x, int y, int val, int size) {
    if (size == 1) {
        H[x][y] = val;
        return;
    }
    int newSize = size >> 1;
    recur(H, x, y, val, newSize);
    recur(H, x, y + newSize, val - 1, newSize);
    recur(H, x + newSize, y, val + 1, newSize);
    recur(H, x + newSize, y + newSize, val, newSize);
}

int main() {
    int a, b;
    cin >> a >> b;
    a = 1 << a;
    vector<vector<int>> H(a, vector<int>(a));
    recur(H, 0, 0, b, a);
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < a; ++j) {
            cout << H[i][j] << " ";
        }
        cout << "\n";
    }
}