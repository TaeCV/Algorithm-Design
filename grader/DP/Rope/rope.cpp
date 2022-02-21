#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, M[4005];

int process(int left) {
    if (left < 0)
        return -1;
    if (left == 0)
        return 0;
    if (M[left])
        return M[left];
    int tmp = max(process(left - a), max(process(left - b), process(left - c)));
    if (tmp < 0)
        return M[left] = -1;
    return M[left] = 1 + tmp;
}

int process() {
    return 1 + max(max(process(n - a), process(n - b)), process(n - c));
}

int main() {
    cin >> n >> a >> b >> c;
    cout << process();
}