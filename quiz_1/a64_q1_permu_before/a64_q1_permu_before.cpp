#include <bits/stdc++.h>

using namespace std;

map<int, int> R;

void permu(int n, int len, vector<int> &A, vector<set<int>> &M, bool status, int idx) {
    if (status && len < n) {
        for (int i = 0; i < n; ++i) {
            if (len == 0)
                idx = i;
            A[len] = i;
            if (R.find(i) != R.end()) {
                status = M[idx].find(R[i]) != M[idx].end();
            }
            if (M[idx].find(i) == M[idx].end()) {
                M[idx].insert(i);
                permu(n, len + 1, A, M, status, idx);
                M[idx].erase(i);
                status = true;
            }
        }
    } else if (status) {
        for (int &x : A)
            cout << x << " ";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<int> A(n);
    vector<set<int>> M(21);
    while (m--) {
        cin >> a >> b;
        R[b] = a;
    }
    permu(n, 0, A, M, true, 0);
}