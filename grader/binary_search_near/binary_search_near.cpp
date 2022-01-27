#include <bits/stdc++.h>

using namespace std;

int binary_search_near(vector<int> &db, int k, int l, int r) {
    if (r < l)
        return -1;
    int mid = (l + r) / 2;
    if (db[mid] == k)
        return db[mid];
    else if (db[mid] < k) {
        int result = binary_search_near(db, k, mid + 1, r);
        return result < db[mid] ? db[mid] : result;
    } else {
        return binary_search_near(db, k, l, mid - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m;
    vector<int> db(n);
    for (int i = 0; i < n; ++i) {
        cin >> db[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> k;
        cout << binary_search_near(db, k, 0, n - 1) << "\n";
    }
}
