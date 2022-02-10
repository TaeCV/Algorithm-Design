#include <bits/stdc++.h>

using namespace std;

void tiling(int n, int x, int y, int X, int Y) {
    int newN = n >> 1;
    int quad = (X - x >= newN) + ((Y - y >= newN) << 1);
    cout << quad << " " << x + newN - 1 << " " << y + newN - 1 << "\n";
    if (n == 2) {
        return;
    }
    switch (quad) {
    case 0:
        tiling(newN, x, y, X, Y);
        tiling(newN, x, y + newN, x + newN - 1, y + newN);
        tiling(newN, x + newN, y, x + newN, y + newN - 1);
        tiling(newN, x + newN, y + newN, x + newN, y + newN);
        break;
    case 1:
        tiling(newN, x, y, x + newN - 1, y + newN - 1);
        tiling(newN, x, y + newN, x + newN - 1, y + newN);
        tiling(newN, x + newN, y, X, Y);
        tiling(newN, x + newN, y + newN, x + newN, y + newN);
        break;
    case 2:
        tiling(newN, x, y, x + newN - 1, y + newN - 1);
        tiling(newN, x, y + newN, X, Y);
        tiling(newN, x + newN, y, x + newN, y + newN - 1);
        tiling(newN, x + newN, y + newN, x + newN, y + newN);
        break;
    default: // case 3
        tiling(newN, x, y, x + newN - 1, y + newN - 1);
        tiling(newN, x, y + newN, x + newN - 1, y + newN);
        tiling(newN, x + newN, y, x + newN, y + newN - 1);
        tiling(newN, x + newN, y + newN, X, Y);
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int L, X, Y;
    cin >> L >> X >> Y;
    cout << L * L / 3 << "\n";
    tiling(L, 0, 0, X, Y);
}