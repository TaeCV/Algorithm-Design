#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;

bool isValid(int col[], int idx) {
    for (int i = 0; i < idx; ++i)
        if (idx - i == abs(col[idx] - col[i]))
            return false;
    return true;
}

void cal(int col[], int idx) {
    if (idx == N)
        ans++;
    else {
        for (int i = idx; i < N; ++i) {
            swap(col[i], col[idx]);
            if (isValid(col, idx))
                cal(col, idx + 1);
            swap(col[i], col[idx]);
        }
    }
}

int main() {
    cin >> N;
    int col[N];
    for (int i = 0; i < N; ++i)
        col[i] = i;
    cal(col, 0);
    cout << ans;
}