#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;

bool isValid(int col[], int idx) {
    for (int i = 0; i < idx; ++i) {
        if (col[idx] == col[i] || (idx - i) == abs(col[idx] - col[i]))
            return false;
    }
    return true;
}

void nQueen(int col[], int idx) {
    if (idx == N) {
        ans++;
    } else {
        for (int i = 1; i <= N; ++i) {
            col[idx] = i;
            if (isValid(col, idx))
                nQueen(col, idx + 1);
        }
    }
}

int main() {
    cin >> N;
    int col[N];
    nQueen(col, 0);
    cout << ans;
}