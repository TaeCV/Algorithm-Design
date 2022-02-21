#include <bits/stdc++.h>

using namespace std;
int N, W, K, I[2][200005], M[2][200005][50];

int process(int i, int side, int quota) {
    if (quota <= 0 || i > N)
        return 0;
    // side = 1 equals to right, side = 0 equals to left
    if (M[side][i][0] > 0)
        return M[side][i][0];
    if (i == N)
        return M[side][i][0] = I[side][i];
    return M[side][i][0] = max(I[side][i] + process(i + W + 1, side ^ 1, quota - 1), process(i + 1, side, quota));
}

int process2(int i, int side, int quota) {
    if (quota <= 0 || i > N)
        return 0;
    // side = 1 equals to right, side = 0 equals to left
    if (M[side][i][quota] > 0)
        return M[side][i][quota];
    if (i == N)
        return M[side][i][quota] = I[side][i];
    return M[side][i][quota] = max(I[side][i] + process2(i + W + 1, side ^ 1, quota - 1), process2(i + 1, side, quota));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> W >> K;
    for (int i = 1; i <= N; ++i)
        cin >> I[0][i];
    for (int i = 1; i <= N; ++i)
        cin >> I[1][i];
    cout << (K < N ? max(process2(1, 0, K), process2(1, 1, K)) : max(process(1, 0, K), process(1, 1, K)));
}