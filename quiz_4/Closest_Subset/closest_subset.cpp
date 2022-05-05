#include <bits/stdc++.h>

using namespace std;

int n, m, k, A[100], ans = INT_MAX;
bool used[100];

int sumLeft(int quota, int idx) {
    int sm = 0;
    for (int i = idx; i < n && quota > 0; ++i, quota--)
        sm += A[i];
    return sm;
}

void cal(int len, int sm, int quota) {
    if (len == n) {
        if (quota > 0)
            return;
        ans = min(abs(k - sm), ans);
    } else {
        if (abs(k - sm - sumLeft(quota, len)) > ans)
            return;
        if (quota > 0) {
            cal(len + 1, sm + A[len], quota - 1);
        }
        cal(len + 1, sm, quota);
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    sort(A, A + n);
    cal(0, 0, m);
    cout << ans;
}

/*
38 19 4679
880 329 565 77 504 381 428 836 471 758 312 687 45 45 826 604 532 314 349 451 650 858 577 711 820 155 900 42 675 639 361 180 893 354 489 174 200 33

22
*/