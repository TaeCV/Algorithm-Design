#include <bits/stdc++.h>

using namespace std;

vector<int> pareto(vector<pair<int, int>> &X, int l, int r) {
    if (r == l)
        return {l};
    if (r - l < 2) {
        if (X[l].second > X[r].second)
            return {l, r};
        return {r};
    }
    int m = (l + r) >> 1;
    vector<int> a = pareto(X, l, m);
    vector<int> b = pareto(X, m + 1, r);
    for (int x : a) {
        if (X[x].second > X[b[0]].second) {
            b.push_back(x);
        } else
            break;
    }
    sort(b.begin(), b.end());
    return b;
}

int main() {
    int N, x, y;
    cin >> N;
    vector<pair<int, int>> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        X[i] = {x, y};
    }
    sort(X.begin(), X.end());
    cout << pareto(X, 0, N - 1).size();
}