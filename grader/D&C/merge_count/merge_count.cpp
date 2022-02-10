#include <bits/stdc++.h>

using namespace std;

void merge_count(int start, int end, int &k) {
    int mid = (start + end + 1) >> 1;
    if (end > start + 1 && k) {
        --k;
        merge_count(mid, end, k);
        merge_count(start, mid, k);
    } else {
        while (start < end) {
            cout << ++start << " ";
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    if ((k & 1) && ((k >>= 1) < n))
        merge_count(0, n, k);
    else
        cout << "-1";
}