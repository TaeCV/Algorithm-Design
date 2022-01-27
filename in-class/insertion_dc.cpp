#include <bits/stdc++.h>

using namespace std;

void insertion_dc(vector<int> &a, int l, int r) {
    // Version right->left
    if (l < r) {
        insertion_dc(a, l + 1, r);
        int tmp = a[l], i = l + 1;
        for (; i <= r; ++i) {
            if (tmp <= a[i])
                break;
            a[i - 1] = a[i];
        }
        a[i - 1] = tmp;
    }
}

void insertion_dc_2(vector<int> &a, int l, int r) {
    // Version left->right
    if (l < r) {
        insertion_dc_2(a, l, r - 1);
        int tmp = a[r], i;
        for (i = r - 1; i >= l; --i) {
            if (tmp >= a[i])
                break;
            a[i + 1] = a[i];
        }
        a[i + 1] = tmp;
    }
}

void insertion(vector<int> &a) {
    insertion_dc_2(a, 0, a.size() - 1);
}

int main() {
    vector<int> test = {8, 1, 23, 4, 5, 6};
    insertion(test);
    for (auto x : test)
        cout << x << " ";
}