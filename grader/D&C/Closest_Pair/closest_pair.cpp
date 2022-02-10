#include <bits/stdc++.h>

using namespace std;

int distance(int x1, int x2, int y1, int y2) { return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); }

int closest(vector<int> &X, vector<int> &Y, int l, int r) {
    if (r == l)
        return INT_MAX;
    if (r - l == 1) {
        return distance(X[l], X[r], Y[l], Y[r]);
    }
    int m = (l + r) >> 1;
    int b = min(closest(X, Y, l, m), closest(X, Y, m + 1, r));
    vector<pair<int, int>> xyInStripLeft(m - l + 1, {INT_MAX, INT_MAX}), xyInStripRight(r - m, {INT_MAX, INT_MAX});
    int c = 0, d = 0;
    for (int i = l; i <= m; ++i) {
        if (abs((X[i] - X[m]) * (X[i] - X[m])) <= b)
            xyInStripLeft[c++] = {Y[i], X[i]};
    }
    for (int i = m + 1; i <= r; ++i) {
        if (abs((X[i] - X[m]) * (X[i] - X[m])) <= b)
            xyInStripRight[d++] = {Y[i], X[i]};
    }
    sort(xyInStripLeft.begin(), xyInStripLeft.end());
    sort(xyInStripRight.begin(), xyInStripRight.end());
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < d; ++j) {
            if (abs((xyInStripLeft[i].first - xyInStripRight[j].first) * (xyInStripLeft[i].first - xyInStripRight[j].first)) <= b) {
                b = min(b, distance(xyInStripLeft[i].second, xyInStripRight[j].second, xyInStripLeft[i].first, xyInStripRight[j].first));
            }
        }
    }
    return b;
}

int main() {
    int N, x, y;
    cin >> N;
    vector<pair<int, int>> XY(N);
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        XY[i] = {x, y};
    }
    sort(XY.begin(), XY.end());
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i) {
        X[i] = XY[i].first;
        Y[i] = XY[i].second;
    }
    cout << closest(X, Y, 0, N - 1);
}