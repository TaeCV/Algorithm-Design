#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> DP;

int cal(int sm, int last) {
    if (sm == 0)
        return 1;
    if (DP[sm][last] != -1)
        return DP[sm][last];
    DP[sm][last] = 0;
    for (int i = last; i <= N; ++i)
        if (sm - i >= 0)
            DP[sm][last] += cal(sm - i, i);
    return DP[sm][last];
}

int main() {
    cin >> N;
    DP = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
    cout << cal(N, 1);
}