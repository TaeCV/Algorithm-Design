#include <bits/stdc++.h>

using namespace std;
int N, M, A[100005], K;

int binary_search_near_repeat() {
    int l = -1, r = N - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (A[mid] <= K)
            l = mid;
        else
            r = mid - 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    while (M--) {
        cin >> K;
        if (A[0] > K) {
            cout << "-1\n";
            continue;
        }
        cout << binary_search_near_repeat() << "\n";
    }
}