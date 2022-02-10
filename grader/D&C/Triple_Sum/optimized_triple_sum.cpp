#include <bits/stdc++.h>

using namespace std;

bool triple_sum(int q, vector<int> &A, vector<pair<int, int>> &S) {
    int remain, N = A.size(), stop = S.size() - 1;
    for (int i = 0; i < N - 2; ++i) {
        remain = q - A[i];
        int l = 0, r = stop;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (remain == S[m].first) {
                if (S[m].second - 1 >= i)
                    return true;
                (i < S[m].second - 1) ? r = m - 1 : l = m + 1;
            }
            (remain < S[m].first) ? r = m - 1 : l = m + 1;
        }
    }
    return false;
}

int main() {
    int N, M, q;
    cin >> N >> M;
    vector<int> A(N);
    vector<pair<int, int>> S;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        for (int j = 0; j < i; ++j)
            S.push_back({A[i] + A[j], j});
    }
    sort(S.begin(), S.end());
    while (M--) {
        cin >> q;
        cout << (triple_sum(q, A, S) ? "YES\n" : "NO\n");
    }
}