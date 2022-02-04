#include <bits/stdc++.h>

using namespace std;

long long thanos(int A, int B, int start, int end, vector<int> &pos) {
    if (start == end) {
        auto it = lower_bound(pos.begin(), pos.end(), start);
        auto it2 = upper_bound(pos.begin(), pos.end(), start);
        return (it2 > it) ? B * (it2 - it) : A;
    }
    int mid = (start + end) >> 1;
    auto it = lower_bound(pos.begin(), pos.end(), start);
    auto it2 = upper_bound(pos.begin(), pos.end(), end);
    if (it2 > it) {
        long long a = thanos(A, B, start, mid, pos) + thanos(A, B, mid + 1, end, pos);
        long long b = B * (it2 - it) * (end - start + 1);
        return min(a, b);
    }
    return A;
}

int main() {
    int p, k, A, B;
    cin >> p >> k >> A >> B;
    p = 1 << p;
    vector<int> pos(k);
    for (int i = 0; i < k; ++i) {
        cin >> pos[i];
        --pos[i];
    }
    sort(pos.begin(), pos.end());
    cout << thanos(A, B, 0, p - 1, pos);
}