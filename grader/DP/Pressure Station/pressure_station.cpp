#include <bits/stdc++.h>

using namespace std;
int N, K, P[10005], M[10005];

int process(int lastUsed) {
    int center = lastUsed + K + 1;
    if (center > N)
        return 0;
    if (M[lastUsed] > 0)
        return M[lastUsed];
    int ans = INT_MAX;
    for (int i = center - K; i <= center + K && i <= N; ++i) {
        ans = min(ans, process(i) + P[i]);
    }
    M[lastUsed] = ans;
    return ans;
}

int process() {
    int ans = INT_MAX;
    for (int i = 1; i <= K + 1; ++i) {
        ans = min(ans, process(i) + P[i]);
    }
    return ans;
}

int main() {
    cin >> N >> K;
    int mn = INT_MAX;
    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
        mn = min(P[i], mn);
    }
    if (K + 1 >= N)
        cout << mn;
    else {
        cout << process();
    }
}

/*
20 3
128 219 95 974 403 925 274 841 717 44 559 886 997 940 172 908 621 872 481 571

10 3
260 241 865 354 3 626 225 335 243 405

50 24
910 181 98 366 344 458 665 193 798 633 708 980 213 224 962 36 890 453 158 804 64 710 610 532 9 742 86 842 463 738 506 885 774 726 99 540 569 575 334 972 563 445 732 912 37 151 914 177 333 626
*/