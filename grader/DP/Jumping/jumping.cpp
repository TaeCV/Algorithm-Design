#include <bits/stdc++.h>

using namespace std;

int N, B[1000005], M[1000005];

int process(int idx) {
    if (idx > N)
        return 0;
    if (M[idx] > 0)
        return M[idx];
    if (idx == N - 1)
        return M[idx] = B[idx] + process(idx + 1);
    else if (idx == N - 2)
        return M[idx] = B[idx] + max(process(idx + 1), process(idx + 2));
    return M[idx] = B[idx] + max(max(process(idx + 1), process(idx + 2)), process(idx + 3));
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> B[i];
    cout << process(1);
}